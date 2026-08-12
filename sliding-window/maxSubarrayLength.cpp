// 2958. Length of Longest Subarray With at Most K Frequency
// Time complexity -> O(n)
// Space Complexity -> O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;

    int i = 0, j = 0;
    int result = 0;

    while (j < n) {
        int curr = nums[j];
        mp[curr]++;

        // check if the requirement fails
        while (mp[curr] > k) {
            mp[nums[i]]--;
            i++;
        }

        result = max(result, j - i + 1);
        j++;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    cout << maxSubarrayLength(nums, k);

    return 0;
}