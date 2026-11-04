#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        if (x == 0)
            return 0;

        int n = nums.size();
        int result = INT_MAX;

        // get the prefix sum of the array
        vector<int> preSum(n, 0);

        preSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            preSum[i] = nums[i] + preSum[i - 1];

        // sliding window now
        int target = preSum[n - 1] - x;
        int i = 0;
        int j = 0;

        int remSum = 0;

        while (j < n) {
            int currSum = preSum[j] - remSum;

            while (currSum > target && i < j) {
                currSum -= nums[i];
                remSum += nums[i];
                i++;
            }

            if (currSum == target)
                result = min(result, n - (j - i + 1));

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    vector<int> nums = {8828, 9581, 49, 9818, 9974, 9869, 9991, 10000, 10000, 10000, 9999, 9993, 9904, 8819, 1231, 6309};
    int x = 134365;

    Solution s;
    cout << s.minOperations(nums, x);

    return 0;
}