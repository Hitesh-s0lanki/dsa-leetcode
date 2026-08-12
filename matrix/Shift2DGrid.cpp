#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    deque<int> que;

    int m = grid.size();
    int n = grid[0].size();

    // prepare the dequeue
    for (vector<int> row : grid)
        for (int element : row)
            que.push_back(element);

    // getting the same rotating
    k = k % (m * n);

    // rotate the element
    while (k != 0) {
        int last = que.back();
        que.pop_back();
        que.push_front(last);

        k--;
    }

    // again get the element update
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = que.front();
            que.pop_front();
        }
    }

    return grid;
}

int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;

    vector<vector<int>> result = shiftGrid(grid, k);

    for (const vector<int> &row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}