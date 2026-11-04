#include <iostream>

using namespace std;

class Solution {
public:
    int dp[1001][1001];
    typedef unsigned long long ull;

    int solveMem(string s, string t, int m, int n) {
        // base case
        if (n == 0)
            return dp[m][n] = 1;
        if (m == 0)
            return dp[m][n] = 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1])
            return dp[m][n] = solve(s, t, m - 1, n) + solve(s, t, m - 1, n - 1);

        return dp[m][n] = solve(s, t, m - 1, n);
    }

    int solve(string s, string t, int m, int n) {
        // base case
        if (n == 0)
            return 1;
        if (m == 0)
            return 0;

        if (s[m - 1] == t[n - 1])
            return solve(s, t, m - 1, n) + solve(s, t, m - 1, n - 1);

        return solve(s, t, m - 1, n);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        // if (m < n)
        //     return 0;

        // memset(dp, -1, sizeof(dp));
        // return solveMem(s, t, m, n);

        // Bottom Up array
        // vector<vector<ull>> dp(m + 1, vector<ull>(n + 1));

        // // Set the base cases
        // for (int i = 0; i < m; i++)
        //     dp[i][0] = 1;

        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (s[i - 1] == t[j - 1])
        //             dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        //         else
        //             dp[i][j] = dp[i - 1][j];
        //     }
        // }

        vector<ull> prev(n + 1, 0);
        vector<ull> curr(n + 1, 0);

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j] + prev[j - 1];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return curr[n];
    }
};

int main() {
    string s = "rabbbit", t = "rabbit";

    Solution st;
    cout << st.numDistinct(s, t);

    return 0;
}