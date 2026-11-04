// T.C : O(N·log N + Q·log N)
// S.C : O(N·log N)

#include <iostream>

using namespace std;

class Solution {
public:
    int M = 1e9 + 7;
    int rows, cols;

    vector<vector<int>> adj;
    vector<vector<int>> ancestorTable;
    vector<int> depth;
    vector<int> pow2;

    void preComputePow2() {
        pow2.resize(rows + 1);
        pow2[0] = 1;

        for (int i = 1; i <= rows; i++)
            pow2[i] = (2LL * pow2[i - 1]) % M;
    }

    void createAdj(vector<vector<int>> &edges, int n) {
        adj.resize(n, vector<int>());

        for (auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int node, int parent) {
        ancestorTable[node][0] = parent;

        for (int &ngbr : adj[node]) {
            if (ngbr != parent) {
                depth[ngbr] = depth[node] + 1;
                dfs(ngbr, node);
            }
        }
    }

    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < rows; node++) {
                if (ancestorTable[node][j - 1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    int findKthAncestor(int k, int node) {
        for (int j = 0; j < cols; j++) {
            if (k & (1 << j))
                node = ancestorTable[node][j];
        }
        return node;
    }

    int findLCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int k = depth[u] - depth[v];

        u = findKthAncestor(k, u);

        // on the same node
        if (u == v)
            return u;

        // new logic for the ancestor
        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != -1 && ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        rows = edges.size() + 1;
        cols = log2(rows) + 1;

        createAdj(edges, rows);

        depth.resize(rows, 0);
        ancestorTable.resize(rows, vector<int>(cols, -1));

        // call the dfs
        dfs(0, -1);
        buildAncestorTable();

        preComputePow2();

        vector<int> result;
        for (auto &query : queries) {
            int u = query[0] - 1;
            int v = query[1] - 1;

            int lca = findLCA(u, v);

            int d = depth[u] + depth[v] - (2 * depth[lca]);

            if (d == 0)
                result.push_back(0);
            else
                result.push_back(pow2[d - 1]);
        }

        return result;
    }
};

int main() {
    return 0;
}