#include <iostream>
#include <queue>

using namespace std;

vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    // Build adjacency list
    vector<vector<int>> adj(n);
    for (auto &edge : invocations) {
        adj[edge[0]].push_back(edge[1]);
    }

    // Step 1: Find all suspicious methods (reachable from k)
    vector<bool> suspicious(n, false);
    queue<int> q;

    q.push(k);
    suspicious[k] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!suspicious[v]) {
                suspicious[v] = true;
                q.push(v);
            }
        }
    }

    // Step 2: Check whether any non-suspicious method invokes a suspicious one
    for (auto &edge : invocations) {
        int u = edge[0];
        int v = edge[1];

        if (!suspicious[u] && suspicious[v]) {
            // Cannot remove the suspicious group
            vector<int> ans;
            for (int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
        }
    }

    // Step 3: Remove all suspicious methods
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!suspicious[i])
            ans.push_back(i);
    }

    return ans;
}

int main() {
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
    int n = 4, k = 1;

    vector<int> ans = remainingMethods(n, k, invocations);

    for (int i : ans)
        cout << i << ", ";
    cout << endl;

    return 0;
}