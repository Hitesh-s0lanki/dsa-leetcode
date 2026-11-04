#include <iostream>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; i++)
            diff[i] = abs(nums1[i] - nums2[i]);

        int maxDiff = *max_element(diff.begin(), diff.end());

        vector<int> freq(maxDiff + 1, 0);
        for (int d : diff)
            freq[d]++;

        int operation = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && operation > 0; currDiff--) {
            int countOps = min(freq[currDiff], operation);

            freq[currDiff] -= countOps;
            freq[currDiff - 1] += countOps;
            operation -= countOps;
        }

        long long result = 0;
        for (long long d = 1; d <= maxDiff; d++)
            result += freq[d] * d * d;

        return result;
    }
};

int main() {
    return 0;
}