#include <iostream>

using namespace std;

class Solution {
public:
    int solve(int i, bool buy, vector<int> &prices) {
        if (i == prices.size())
            return 0;

        int profit = 0;

        if (buy)
            profit = max((-prices[i]) + solve(i + 1, false, prices), solve(i + 1, false, prices));
        else
            profit = max(prices[i] + solve(i + 1, true, prices), solve(i + 1, true, prices));

        return profit;
    }

    int solveMemo(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp) {
        if (i == prices.size())
            return dp[i][buy] = 0;

        int profit = 0;

        if (buy)
            profit = max((-prices[i]) + solveMemo(i + 1, false, prices, dp), solveMemo(i + 1, false, prices, dp));
        else
            profit = max(prices[i] + solveMemo(i + 1, true, prices, dp), solveMemo(i + 1, true, prices, dp));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int> &prices) {
        // return solve(0, 1, prices);

        int n = prices.size();

        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solveMemo(0, 1, prices, dp);

        // tabulation
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy)
                    profit = max((-prices[index]) + solveMemo(index + 1, false, prices, dp), solveMemo(index + 1, false, prices, dp));
                else
                    profit = max(prices[index] + solveMemo(index + 1, true, prices, dp), solveMemo(index + 1, true, prices, dp));

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution st;
    cout << st.maxProfit(prices);

    return 0;
}