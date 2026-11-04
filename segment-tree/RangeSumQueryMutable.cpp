#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildTree(int idx, int left, int right, vector<int> &nums) {
        // base case
        if (left == right) {
            segmentTree[idx] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        // build the left sub Tree
        buildTree(2 * idx + 1, left, mid, nums);
        // build the right sub Tree
        buildTree(2 * idx + 2, mid + 1, right, nums);

        segmentTree[idx] = segmentTree[2 * idx + 1] + segmentTree[2 * idx + 2];
    }

    int querySegmentTree(int idx, int left, int right, int queryStart, int queryEnd) {
        if (left > queryEnd || right < queryStart)
            return 0;

        if (left >= queryStart && right <= queryEnd)
            return segmentTree[idx];

        int mid = left + (right - left) / 2;

        return querySegmentTree(2 * idx + 1, left, mid, queryStart, queryEnd) + querySegmentTree(2 * idx + 2, mid + 1, right, queryStart, queryEnd);
    }

    void updateSegmentTree(int idx, int left, int right, int index, int val) {
        // base case
        if (left == right && left == index) {
            segmentTree[idx] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid)
            updateSegmentTree(2 * idx + 1, left, mid, index, val);
        else
            updateSegmentTree(2 * idx + 2, mid + 1, right, index, val);

        segmentTree[idx] = segmentTree[2 * idx + 1] + segmentTree[2 * idx + 2];
    }

    NumArray(vector<int> &nums) {
        this->n = nums.size();
        segmentTree.resize(4 * n);

        // build Tree
        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateSegmentTree(0, 0, this->n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return querySegmentTree(0, 0, this->n - 1, left, right);
    }
};
int main() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << '\n';  // 9
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << '\n';  // 8

    return 0;
}
