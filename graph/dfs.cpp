#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createAdj(vector<vector<int>> edges, int n, int e){
    vector<vector<int>> adj(n);
    for(int i = 0 ;i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    return adj;
}

void dfs(int n, vector<vector<int>>& adj, vector<int>& visited, vector<int> ans){

    // the node which is visit
    ans.push_back(n);
    visited[n] = true;

    for(int i:adj[n]){
        if(!visited[i]){
            dfs(i, adj, visited, ans);
        }
    }
    
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    
    // create the adj list 
    vector<vector<int>> adj = createAdj(edges, V, E);

    //variables for the visited and ans
    vector<int> visited(V, 0);
    vector<vector<int>> ans;

    //start the dfs 
    for(int i = 0; i < V; i++){
        vector<int> temp;
        if(!visited[i]){
            dfs(i, adj, visited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main() {



    return 0;
}