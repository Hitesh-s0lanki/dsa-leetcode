#include <iostream>

using namespace std;

int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();

    if (n <= 2)
        return n;

    int ans = 1;

    while (ans < n)
        ans <<= 1;

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << uniqueXorTriplets(nums);

    return 0;
}