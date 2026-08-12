#include <iostream>
#include <stack>
#include <queue> 

using namespace std;

void topologicalSortDfs(int node, vector<vector<int>> adj, vector<int>& visited, stack<int>& st){

    visited[node] = true;

    for(int neighbour:adj[node]){
        if(!visited[neighbour]){
            topologicalSortDfs(neighbour, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int n, int e) {

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // common map and ans 
    // vector<int> visited(n, 0);
    vector<int> ans;

    // // using th dfs
    // stack<int> st;
    // for(int i = 0; i < n; i++){
    //     if(!visited[i]){
    //         topologicalSortDfs(i, adj, visited, st);
    //     }
    // }

    // // put into the answer array 
    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }

    // using the bfs
    vector<int> indegree(n);
    for(int i = 0; i < n; i++){
        for(int j: adj[i]){
            indegree[i]++;
        }
    }

    queue<int> que;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) 
            que.push(i); 
    }

    while(!que.empty()){
        int front = que.front();
        que.pop();

        ans.push_back(front);

        for (int neighbour: adj[front]){
            indegree[neighbour]--;
            if (indegree[neighbour] == 0){
                que.push(neighbour);
            }
        }
    }

    return ans;

}


int main() {
    return 0;
}

// #include <bits/stdc++.h> 

// vector<int> topologicalSort(vector<vector<int>>& edges, int n, int e) {

//     vector<int> adj[n];
//     for( int i = 0; i < e; i++ ) {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//     }

//     vector<int> indegree(n);
//     for( int i = 0; i < n; i++ ) {
//         for( auto j : adj[i] ) {
//             indegree[j]++;
//         }
//     }


//     queue<int> q;
//     for( int i = 0; i < n; i++ ) {
//         if( indegree[i] == 0 ) {
//             q.push(i);
//         }
//     }

//     vector<int> ans;
//     while( !q.empty() ) {
//         int frontNode = q.front();
//         ans.push_back(frontNode);
//         q.pop();

//         for( int i : adj[frontNode] ) {
//             indegree[i]--;
//             if( indegree[i] == 0 ) {
//                 q.push(i);
//             }
//         }
//     }

//     return ans;
// }