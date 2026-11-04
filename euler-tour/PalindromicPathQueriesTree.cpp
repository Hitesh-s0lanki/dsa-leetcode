#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    int n, time;

    vector<int> tin, tout, eulerTour;

    void dfs(int node, int parent, string &s) {
        tin[node] = time;
        eulerTour[time] = (1 << (s[node] -
                                 'a'));
        time++;

        for (int &child : adj[node]) {
            if (child == parent)
                continue;
            dfs(child, node, s);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] -
                                 'a'));
        time++;
    }

    vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s, vector<string> &queries) {
        this->n = n;
        adj.resize(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        eulerTour.assign(2 * n, 0);

        // fill the euler array
        time = 0;
        dfs(0, -1, s);

        // Build the Segment Tree for the array
    }
};

int main() {
    return 0;
}