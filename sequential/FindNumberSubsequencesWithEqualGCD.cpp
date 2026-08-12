#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int __gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;

        a = b;

        b = remainder;
    }

    return a;
}

int solve(vector<int> &nums, int i, int first, int second) {
    if (i == nums.size()) {
        bool bothNotEmpty = (first != 0 && second != 0);
        bool gcdsMatch = (first == second);

        return (bothNotEmpty && gcdsMatch) ? 1 : 0;
    }

    // skip the case
    int skip = solve(nums, i + 1, first, second);

    // include in first subset
    int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

    // include in second subset
    int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));

    return skip + take1 + take2;
}

int solveMemo(vector<int> &nums, int i, int first, int second, vector<vector<vector<int>>> dp) {
    if (i == nums.size()) {
        bool bothNotEmpty = (first != 0 && second != 0);
        bool gcdsMatch = (first == second);

        return (bothNotEmpty && gcdsMatch) ? 1 : 0;
    }

    // skip the case
    int skip = solve(nums, i + 1, first, second);

    // include in first subset
    int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

    // include in second subset
    int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));

    return skip + take1 + take2;
}

int subsequencePairCount(vector<int> &nums) {
    return solve(nums, 0, 0, 0);
}

class Solution {
    int MOD = 1e9 + 7;

public:
    int subsequencePairCount(vector<int> &nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums)
            maxEl = max(maxEl, x);

        // prev = layer i+1, curr = layer i   (2D instead of 3D)
        vector<vector<int>> prev(maxEl + 1, vector<int>(maxEl + 1, 0));

        // Base case
        for (int first = maxEl; first >= 0; first--) {
            for (int second = maxEl; second >= 0; second--) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch = (first == second);
                prev[first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(maxEl + 1, vector<int>(maxEl + 1, 0));
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {
                    // Skip this index entirely
                    int skip = prev[first][second];

                    // Include this index in seq1
                    int take1 = prev[__gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = prev[first][__gcd(second, nums[i])];

                    curr[first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }

        return prev[0][0];
    }
};

int main() {
    return 0;
}