#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> ans){
    for(int i:ans){
        cout<<i<<", ";
    }
    cout<<endl;
}



vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<int> ans;
   
    queue<int> que;
    vector<int> visited(n);

    que.push(0);

    for(int i = 0; i < n; i++){
        if(!visited[i]){

            while(!que.empty()){
                int front = que.front();
                que.pop();

                ans.push_back(front);

                for(int i:adj[front]){
                    if(!visited[i])
                    que.push(i);
                }
            }

        }

        
    }

    return ans;
}



int main() {

    vector<vector<int>> adj = { {1,2,3},{4}, {5}, {},{},{}};

    vector<int> ans = bfsTraversal(adj.size(), adj);

    print(ans);

    return 0;
}