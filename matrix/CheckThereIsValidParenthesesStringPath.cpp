#include <iostream>

using namespace std;

class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solveRec(int i, int j, int openCnt, vector<vector<char>> &grid) {
        openCnt += grid[i][j] == '(' ? 1 : -1;

        if (openCnt < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return openCnt == 0;

        // move down
        if (i + 1 < m) {
            if (solveRec(i + 1, j, openCnt, grid))
                return true;
        }

        // move down
        if (j + 1 < n) {
            if (solveRec(i, j + 1, openCnt, grid))
                return true;
        }

        return false;
    }

    bool solveMemo(int i, int j, int openCnt, vector<vector<char>> &grid) {
        openCnt += grid[i][j] == '(' ? 1 : -1;

        if (openCnt < 0)
            return dp[i][j][openCnt] = false;

        if (dp[i][j][openCnt] != -1)
            return dp[i][j][openCnt];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][openCnt] = (openCnt == 0);

        // move down
        if (i + 1 < m) {
            if (solveMemo(i + 1, j, openCnt, grid))
                return dp[i][j][openCnt] = true;
        }

        // move down
        if (j + 1 < n) {
            if (solveMemo(i, j + 1, openCnt, grid))
                return dp[i][j][openCnt] = true;
        }

        return dp[i][j][openCnt] = false;
    }

    bool hasValidPath(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // using recursion
        // return solveRec(0, 0, 0, grid);

        // using memo
        // memset(dp, -1, sizeof(dp));
        // return solveMemo(0, 0, 0, grid);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int openCount = 0; openCount <= i + j + 1; openCount++) {
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][openCount] = (openCount == 0);
                        continue;
                    }

                    dp[i][j][openCount] = false;

                    // mode down
                    if (i + 1 < m) {
                        int newOpCount = (grid[i + 1][j] == '(') ? openCount + 1 : openCount - 1;
                        if (newOpCount >= 0 && dp[i + 1][j][newOpCount] == true) {
                            dp[i][j][openCount] = true;
                        }
                    }

                    // mode right
                    if (j + 1 < n) {
                        int newOpCount = (grid[i][j + 1] == '(') ? openCount + 1 : openCount - 1;
                        if (newOpCount >= 0 && dp[i][j + 1][newOpCount] == true) {
                            dp[i][j][openCount] = true;
                        }
                    }
                }
            }
        }

        return dp[0][0][1];
    }
};

int main() {
    return 0;
}