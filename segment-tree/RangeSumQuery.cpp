// Range Sum Query
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> segmentTree;
    // define the segmentTree

    void buildSegmentTree(int i, int l, int r, int arr[]) {
        // base case
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        // build left subTree
        buildSegmentTree(2 * i + 1, l, mid, arr);
        // build right subTree
        buildSegmentTree(2 * i + 2, mid + 1, r, arr);

        // set the current tree root value
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    int querySegmentTree(int startIndex, int endIndex, int index, int l, int r) {
        if (l > endIndex || r < startIndex)
            return 0;

        if (l >= startIndex && r <= endIndex)
            return segmentTree[index];

        int mid = l + (r - l) / 2;

        return querySegmentTree(startIndex, endIndex, 2 * index + 1, l, mid) +
               querySegmentTree(startIndex, endIndex, 2 * index + 2, mid + 1, r);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // intialize this
        segmentTree.resize(4 * n);

        // build the tree
        buildSegmentTree(0, 0, n - 1, arr);

        vector<int> result;
        for (int i = 0; i < 2 * q; i += 2) {
            int start = queries[i] - 1;    // Input is in 1 base indexing
            int end = queries[i + 1] - 1;  // Input is in 1 based indexing

            result.push_back(querySegmentTree(start, end, 0, 0, n - 1));
        }

        return result;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        n = 4,
        q = 2,
        queries[] = {1, 4, 2, 3};

    Solution s;
    vector<int> ans = s.querySum(n, arr, q, queries);

    for (int i : ans)
        cout << i << ", ";

    return 0;
}