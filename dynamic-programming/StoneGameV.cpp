// 1563. Stone Game V
//
// Time Complexity: O(n^3)
//      -> O(n^2) states (l, r) and O(n) work per state to try every split point
// Space Complexity: O(n^2)
//      -> O(n^2) dp table + O(n) prefix sum + O(n) recursion stack (top down)
#include <iostream>

using namespace std;

vector<vector<int>> dp;

// Top Down approach
// Time: O(n^3), Space: O(n^2) memo + O(n) recursion stack
int solve(int l, int r, vector<int> &preSum) {
    // base case
    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int score = 0;

    for (int mid = l; mid <= r - 1; mid++) {
        int leftSum = preSum[mid] - (l - 1 >= 0 ? preSum[l - 1] : 0);
        int rightSum = preSum[r] - preSum[mid];

        if (leftSum < rightSum)
            score = max(score, leftSum + solve(l, mid, preSum));
        else if (leftSum > rightSum)
            score = max(score, rightSum + solve(mid + 1, r, preSum));
        else
            score = max(score, max(leftSum + solve(l, mid, preSum), rightSum + solve(mid + 1, r, preSum)));
    }

    return dp[l][r] = score;
}

// Bottom Up approach
// Time: O(n^3), Space: O(n^2) dp table, no recursion stack
int solve(vector<int> &preSum) {
    int n = preSum.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            int score = 0;
            for (int mid = l; mid <= r - 1; mid++) {
                int leftSum = preSum[mid] - (l - 1 >= 0 ? preSum[l - 1] : 0);
                int rightSum = preSum[r] - preSum[mid];

                if (leftSum < rightSum)
                    score = max(score, leftSum + dp[l][mid]);
                else if (leftSum > rightSum)
                    score = max(score, rightSum + dp[mid + 1][r]);
                else
                    score = max(score, max(leftSum + dp[l][mid], rightSum + dp[mid + 1][r]));
            }

            dp[l][r] = score;
        }
    }

    return dp[0][n - 1];
}

// Time: O(n^3), Space: O(n^2)
int stoneGameV(vector<int> &stoneValue) {
    int n = stoneValue.size();

    dp.assign(501, vector<int>(501, -1));

    vector<int> preSum(n, 0);
    preSum[0] = stoneValue[0];

    for (int i = 1; i < n; i++)
        preSum[i] = stoneValue[i] + preSum[i - 1];

    // return solve(0, n - 1, preSum);
    return solve(preSum);
}

int main() {
    vector<int> stoneValue = {6, 2, 3, 4, 5, 5};

    cout << stoneGameV(stoneValue);

    return 0;
}