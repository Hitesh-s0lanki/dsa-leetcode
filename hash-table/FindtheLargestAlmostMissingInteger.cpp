#include <iostream>

using namespace std;

int largestInteger(vector<int> &nums, int k) {
    int n = nums.size();

    if (k == n)
        return *max_element(nums.begin(), nums.end());

    vector<int> freq(51, 0);
    for (int i : nums)
        freq[i]++;

    // single element window
    if (k == 1) {
        for (int i = 50; i >= 1; i--)
            if (freq[i] == 1)
                return i;
        return -1;
    }

    int result = -1;
    // for the
    if (freq[nums[0]] == 1)
        result = max(result, nums[0]);
    if (freq[nums.back()] == 1)
        result = max(result, nums.back());

    return result;
}

int main() {
    vector<int> nums = {3, 9, 7, 2, 1, 7};
    int k = 4;

    cout << largestInteger(nums, k);

    return 0;
}