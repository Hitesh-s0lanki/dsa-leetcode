#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <climits>
#include <algorithm>

using namespace std;

// Heap version: O(n log 3) time, keeps the 3 largest and 2 smallest in heaps.
int maximumProductHeap(vector<int> &nums) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap; // 3 largest
    priority_queue<int> maxHeap;                            // 2 smallest

    for (int i = 0; i < n; i++) {
        if (minHeap.size() < 3) {
            minHeap.push(nums[i]);
        } else if (minHeap.top() < nums[i]) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }

        if (maxHeap.size() < 2) {
            maxHeap.push(nums[i]);
        } else if (maxHeap.top() > nums[i]) {
            maxHeap.pop();
            maxHeap.push(nums[i]);
        }
    }

    int max3 = minHeap.top();
    minHeap.pop();
    int max2 = minHeap.top();
    minHeap.pop();
    int max1 = minHeap.top();
    minHeap.pop();

    int min2 = maxHeap.top();
    maxHeap.pop();
    int min1 = maxHeap.top();
    maxHeap.pop();

    return max(max1 * max2 * max3, min1 * min2 * max1);
}

// Variable version: single pass, O(1) space.
int maximumProduct(vector<int> &nums) {
    int n = nums.size();
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; // 3 largest
    int min1 = INT_MAX, min2 = INT_MAX;                 // 2 smallest

    for (int i = 0; i < n; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] > max3) {
            max3 = nums[i];
        }

        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
    }

    // Either the three largest, or two most-negative values times the largest.
    return max(max1 * max2 * max3, min1 * min2 * max1);
}

int main() {
    vector<int> a = {-100, -98, -1, 2, 3, 4};
    vector<int> b = {1, 2, 3, 4};
    vector<int> c = {-4, -3, -2, -1};

    cout << maximumProduct(a) << " " << maximumProductHeap(a) << endl; // 39200
    cout << maximumProduct(b) << " " << maximumProductHeap(b) << endl; // 24
    cout << maximumProduct(c) << " " << maximumProductHeap(c) << endl; // -6

    return 0;
}