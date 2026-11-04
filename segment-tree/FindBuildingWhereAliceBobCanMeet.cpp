#include <iostream>

using namespace std;

class Solution {
public:
    void buildSegmentTree(int idx, int start, int end, vector<int> &heights, int *segementTree) {
        if (start == end) {
            segementTree[idx] = start;  // storing the index
            return;
        }

        int mid = start + (end - start) / 2;

        buildSegmentTree(2 * idx + 1, start, mid, heights, segementTree);    // left
        buildSegmentTree(2 * idx + 2, mid + 1, end, heights, segementTree);  // right

        segementTree[idx] = heights[segementTree[2 * idx + 1]] >= heights[segementTree[2 * idx + 2]] ? segementTree[2 * idx + 1] : segementTree[2 * idx + 2];
    }

    int *constructTree(vector<int> &heights, int n) {
        int *segementTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, heights, segementTree);
        return segementTree;
    }

    int querySegmentTree(int queryStart, int queryEnd, int idx, int start, int end, vector<int> &heights, int *segmentTree) {
        if (start > queryEnd || end < queryStart)
            return -1;

        if (start >= queryStart && end <= queryEnd)
            return segmentTree[idx];

        int mid = start + (end - start) / 2;

        int leftIndex = querySegmentTree(queryStart, queryEnd, 2 * idx + 1, start, mid, heights, segmentTree);
        int rightIndex = querySegmentTree(queryStart, queryEnd, 2 * idx + 2, mid + 1, end, heights, segmentTree);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    int RMIQ(int *segmentTree, vector<int> &heights, int n, int queryStart, int queryEnd) {
        return querySegmentTree(queryStart, queryEnd, 0, 0, n - 1, heights, segmentTree);
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries) {
        int n = heights.size();

        int *segmentTree = constructTree(heights, n);  // O(n)

        vector<int> result;

        for (auto &query : queries) {
            int alice = min(query[0], query[1]);
            int bob = max(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                result.push_back(bob);
                continue;
            }

            int start = bob + 1;
            int end = n - 1;

            int resultIdx = INT_MAX;

            // binary search
            while (start <= end) {
                int mid = start + (end - start) / 2;

                int idx = RMIQ(segmentTree, heights, n, start, mid);

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    end = mid - 1;
                    resultIdx = min(resultIdx, idx);
                } else {
                    start = mid + 1;
                }
            }
            result.push_back(resultIdx == INT_MAX ? -1 : resultIdx);
        }

        return result;
    }
};

int main() {
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};

    Solution st;

    vector<int> ans = st.leftmostBuildingQueries(heights, queries);

    for (int i : ans)
        cout << i << "\t";

    return 0;
}