#include <iostream>

using namespace std;

vector<vector<int>> createAdj(int n, vector< pair < int, int >>& edges){

    vector<vector<int>> adj(n);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    return adj;
}

bool cycleDfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfsVisited){

    visited[node] = true;
    dfsVisited[node] = true;

    for(int neighbour: adj[node]){
        if(!visited[neighbour]){
            bool checkCycle = cycleDfs(neighbour, adj, visited, dfsVisited);
            if (checkCycle) return true;
        } else if (dfsVisited[neighbour]) {
            return true;
        }
    }

    dfsVisited[node] = false;

    return false;
}



int detectCycleInDirectedGraph(int n, vector< pair < int, int >>& edges) {

    // create the adj list 
    vector<vector<int>> adj = createAdj(n + 1, edges);

    // extra variable needed 
    vector<int> visited(n + 1, 0);
    vector<int> dfsVisited(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bool cycleDetected = cycleDfs(i, adj, visited, dfsVisited);
            if (cycleDetected) return true;
        }
    }

    return false;
}

int main() {
    return 0;
}