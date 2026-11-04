#include <iostream>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> pl;

    bool isPalindrome(string &s, int i, int j) {
        int left = i;
        int right = j;

        while (left < right) {
            if (s[left] != s[right])
                return pl[i][j] = false;

            left++;
            right--;
        }

        return pl[i][j] = true;
    }

    int solveMem(string &s, int k, int i, int j) {
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pl[i][j] == 1 || isPalindrome(s, i, j)) {
            int takeIt = 1 + solveMem(s, k, j + 1, j + k);
            int grow = solveMem(s, k, i, j + 1);
            int slide = solveMem(s, k, i + 1, j + 1);

            return dp[i][j] = max({takeIt, grow, slide});
        }

        int grow = solveMem(s, k, i, j + 1);
        int slide = solveMem(s, k, i + 1, j + 1);

        return dp[i][j] = max(grow, slide);
    }

    int solveRec(string &s, int k, int i, int j) {
        if (i >= n || j >= n)
            return 0;

        if (isPalindrome(s, i, j)) {
            int takeIt = 1 + solveRec(s, k, j + 1, j + k);
            int grow = solveRec(s, k, i, j + 1);
            int slide = solveRec(s, k, i + 1, j + 1);

            return max({takeIt, grow, slide});
        }

        int grow = solveRec(s, k, i, j + 1);
        int slide = solveRec(s, k, i + 1, j + 1);

        return max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        n = s.length();

        if (k == 1)
            return n;

        // return solveRec(s, k, 0, k - 1);

        // dp.assign(n + 1, vector<int>(n + 1, -1));
        pl.assign(n + 1, vector<int>(n + 1, -1));

        // return solveMem(s, k, 0, k - 1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (pl[i][j] == 1 || isPalindrome(s, i, j)) {
                    int takeIt = 1;

                    if (j + 1 < n && j + k < n) {
                        takeIt += dp[j + 1][j + k];
                    }

                    int grow = dp[i][j + 1];

                    int slide = dp[i + 1][j + 1];

                    dp[i][j] = max({takeIt, grow, slide});

                } else {
                    int grow = dp[i][j + 1];

                    int slide = dp[i + 1][j + 1];

                    dp[i][j] = max(grow, slide);
                }
            }
        }

        return dp[0][k - 1];
    }
};

int main() {
    Solution st;

    cout << st.maxPalindromes("abaccdbbd", 3);

    return 0;
}