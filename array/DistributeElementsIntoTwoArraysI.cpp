#include <iostream>

using namespace std;

vector<int> resultArray(vector<int> &nums) {
    int n = nums.size();

    vector<int> arr1, arr2;
    vector<int> result;

    // initail values
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    int i = 2;
    while (i < n) {
        if (arr1.back() > arr2.back())
            arr1.push_back(nums[i]);
        else
            arr2.push_back(nums[i]);
        i++;
    }

    // merge the both
    i = 0;
    while (i < arr1.size())
        result.push_back(arr1[i++]);
    int j = 0;
    while (j < arr2.size())
        result.push_back(arr2[j++]);

    return result;
}

int main() {
    vector<int> nums = {2, 1, 3};

    vector<int> ans = resultArray(nums);

    for (int i : ans)
        cout << i << ", ";

    return 0;
}