#include <iostream>

using namespace std;

int missingMultiple(vector<int> &nums, int k) {
    // map the order
    vector<bool> mp(101, 0);

    for (int i : nums)
        mp[i] = true;

    int initail = k;

    while (k <= 100) {
        if (!mp[k])
            break;

        k += initail;
    }

    return k;
}

int main() {
    vector<int> nums = {8, 2, 3, 4, 6};

    cout << missingMultiple(nums, 2);

    return 0;
}