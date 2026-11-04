#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int m, n;

    map<tuple<int, int, int>, int> dp;

    int solveMemo(int row, int col,
                  vector<vector<int>> &grid, int val) {
        val ^= grid[row][col];

        if (row == m - 1 && col == n - 1)
            return val;

        auto key = make_tuple(row, col, val);

        if (dp.count(key))
            return dp[key];

        int down = INT_MAX;
        int right = INT_MAX;

        if (row + 1 < m)
            down = solveMemo(row + 1, col, grid, val);

        if (col + 1 < n)
            right = solveMemo(row, col + 1, grid, val);

        return dp[key] = min(down, right);
    }

    int minCost(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();

        dp.clear();

        return solveMemo(0, 0, grid, 0);
    }
};

int main() {
    // vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<vector<int>> grid = {{11, 10, 4}, {19, 9, 13}};

    Solution st;
    cout << st.minCost(grid);

    return 0;
}