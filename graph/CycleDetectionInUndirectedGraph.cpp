#include <iostream>
#include <vector>
#include <queue>

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

bool bfsCycle(vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent, int start) {
    queue<int> que;

    que.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!que.empty()) {
        int front = que.front();
        que.pop();

        for (int neighbour : adj[front]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = front;
                que.push(neighbour);
            }
            else if (neighbour != parent[front]) {
                return true;
            }
        }
    }

    return false;
}

bool dfsCycle(int parent, int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = true;

    for(int neighbour: adj[node]){
        if(!visited[neighbour]){
            bool isCycle = dfsCycle(node, neighbour, adj, visited);
            if(isCycle) return true;
        } else if (neighbour != parent){
            return true;
        }
    }

    return false;
}

// Yes or No
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    // get the adj list 
    vector<vector<int>> adj = createAdj(edges, n + 1, m);

    // define the variable 
    vector<int> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    // // travesal for the bfs
    // for(int i = 1; i <= n; i++){
    //     if(!visited[i] && bfsCycle(adj, visited, parent, i)){
    //         return "Yes";
    //     }
    // }

    // travesal for the dfs
    for(int i = 1; i <= n; i++){
        if(!visited[i] && dfsCycle(-1, 1, adj, visited)){
            return "Yes";
        }
    }

    return "No";
}

int main() {

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};
    int n = 3;

    cout<<cycleDetection(edges, n, edges.size());

    return 0;
}


// #include <queue>

// vector<vector<int>> createAdj(vector<vector<int>>& edges, int n, int e) {

//     // maping edges
//     vector<int> ans[n + 1];
//     for( int i = 0; i < e; i++ ) {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }

//     vector<vector<int>> adj(n + 1);

//     for( int i = 1; i <= n; i++ ) {
//         for( int j : ans[i] ) {
//             adj[i].push_back(j);
//         }
//     }
//     return adj;
// }

// bool solveDFS(vector<vector<int>> adj, vector<int>& visited, int node, int parent) {
//     visited[node] = 1;

//     for( auto neighbour : adj[node] ) {
//         if( !visited[neighbour] ) {
//             bool cycleDetected = solveDFS(adj, visited, neighbour, node);
//             if( cycleDetected ) return true;
//         } else if( neighbour != parent ) {
//             return true;
//         }
//     }

//     return false;
// }

// bool solveBFS(vector<vector<int>> adj, vector<int>& visited, int node, int n) {

//     // travesal bfs
//     queue<int> q;

//     // parent node mapping 
//     vector<int> parent(n + 1);
//     for( int i = 1; i <= n; i++ )
//         parent[i] = -1;

//     q.push(node);
//     visited[node] = 1;

//     while( !q.empty() ) {
//         int frontNode = q.front();
//         q.pop();

//         for( int i : adj[frontNode] ) {
//             if( visited[i] == 1 && i != parent[frontNode] ) {
//                 return true;
//             } else if( visited[i] == 0 ) {
//                 q.push(i);
//                 visited[i] = 1;
//                 parent[i] = frontNode;
//             }
//         }
//     }


//     return false;
// }


// string solve(vector<vector<int>>& adj, int n, int e) {
//     vector<int> visited(n + 1);

//     for( int i = 1; i <= n; i++ ) {
//         if( visited[i] == 0 ) {
//             bool ans = solveDFS(adj, visited, i, n);
//             if( ans ) return "Yes";
//         }
//     }

//     return "No";
// }


// string cycleDetection(vector<vector<int>>& edges, int n, int e) {
//     vector<vector<int>> adj = createAdj(edges, n, e);
//     return solve(adj, n, e);
// }
