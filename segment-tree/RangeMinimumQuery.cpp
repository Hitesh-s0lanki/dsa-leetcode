// Range Minimum Query
//
// Time Complexity: O(n + q * log(n))
//      -> O(n) to build the segment tree, O(log(n)) per query, q queries
// Space Complexity: O(n)
//      -> O(4 * n) for the segment tree + O(log(n)) recursion stack
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> segTree;

    // Time: O(n), Space: O(log(n)) recursion stack
    void buildSegmentTree(int i, int l, int r, vector<int> &arr) {
        // base condition
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        // get the mid of the nodes
        int mid = l + (r - l) / 2;

        // build other side of the tree
        buildSegmentTree(2 * i + 1, l, mid, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, arr);

        segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    // Time: O(log(n)) per query, Space: O(log(n)) recursion stack
    int RMQuery(int start, int end, int i, int l, int r) {
        if (l > end || r < start)
            return INT_MAX;

        if (l >= start && r <= end)
            return segTree[i];

        // get the mid of the nodes
        int mid = l + (r - l) / 2;

        return min(RMQuery(start, end, 2 * i + 1, l, mid), RMQuery(start, end, 2 * i + 2, mid + 1, r));
    }

    // Time: O(n + q * log(n)), Space: O(n) for the tree + O(q) for the result
    vector<int> rangeMinQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        // assign the tree
        segTree.assign(4 * n, 0);

        // build the segment tree
        buildSegmentTree(0, 0, n - 1, arr);

        vector<int> result;
        for (vector<int> element : queries) {
            result.push_back(RMQuery(element[0], element[1], 0, 0, n - 1));
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};

    Solution st;
    vector<int> ans = st.rangeMinQuery(arr, queries);

    // Print the solution
    for (int i : ans)
        cout << i << ", ";

    return 0;
}