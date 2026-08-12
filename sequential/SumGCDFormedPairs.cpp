#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

long long gcdSum(vector<int> &nums) {
    int n = nums.size();
    long long ans = 0;

    vector<int> prefixGCD;

    prefixGCD[0] = nums[0];
    int maxi = nums[0];

    for (int i = 1; i < n; i++) {
        maxi = max(nums[i], maxi);
        prefixGCD[i] = gcd(maxi, nums[i]);
    }

    sort(prefixGCD.begin(), prefixGCD.end());

    for (int i = 0; i < n / 2; i++) {
        ans += gcd(prefixGCD[i], prefixGCD[n - 1 - i]);
    }

    return ans;
}

int main() {
    return 0;
}