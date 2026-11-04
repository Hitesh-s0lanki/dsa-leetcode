#include <iostream>

using namespace std;

class Solution {
public:
    int dp[1001][1001];

    bool solve(string &s, int i, int j) {
        // base condition
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1);

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int start_index = 0;
        int max_len = INT_MIN;

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > max_len) {
                        start_index = i;
                        max_len = j - i + 1;
                    }
                }
            }
        }

        return s.substr(start_index, max_len);
    }
};

int main() {
    string s = "babad";

    Solution obj;
    cout << obj.longestPalindrome(s);

    return 0;
}