#include <iostream>
#include <cmath>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> ancestorTable;
    int rows;
    int cols;

    TreeAncestor(int n, vector<int> &parent) {
        rows = n;
        cols = log2(n) + 1;

        ancestorTable.resize(rows, vector<int>(cols, -1));

        // fill the first row if now then do the dfs for this row
        for (int i = 0; i < rows; i++)
            ancestorTable[i][0] = parent[i];

        // dp for the next tree
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestorTable[node][j - 1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < cols; j++) {
            if (k & (1 << j)) {
                node = ancestorTable[node][j];

                if (node == -1)
                    break;
            }
        }

        return node;
    }
};

int main() {
    return 0;
}