// Multi-source BFS to precompute distances followed by binary search on the answer with path validation.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool checkValid(int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= n) return false;
        return true;
    }

    bool check(vector<vector<int>>& distNearestThief, int sf) {
        queue<pair<int, int>> que;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        //0,0 --> n-1, n-1
        que.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf)
            return false;

        while(!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;

            que.pop();

            if(curr_i == n-1 && curr_j == n-1) {
                return true;
            }

            for(vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if(checkValid(new_i, new_j) && visited[new_i][new_j] != true) {
                    if(distNearestThief[new_i][new_j] < sf) {
                        continue; //reject this cell
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }

            }
        }

        return false;
        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // size of the grid
        n = grid.size();

        //->  step 1: precalculation of the nearest distance between the thief

        // defining the variable 
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push the thief cell inside the queue
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!que.empty()){
            int size = que.size();

            while(size--){
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();

                // initial 0 then 1, 2
                distNearestThief[curr_i][curr_j] = level;

                // for the next adject
                for(vector<int>& dir : directions){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(!checkValid(new_i, new_j) || visited[new_i][new_j]) continue;

                    que.push({ new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }

            level++;
        }

        // apply binary search 
        int left = 0;
        int right = level - 1;
        int result = 0;
        
        while (left <= right){
            
            int mid = left + (right - left)/2;

            if(check(distNearestThief, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }

        return result;
    }
};

int main() {

    vector<vector<int>> grid = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};

    Solution *s = new Solution();
    cout<<"above has a safeness factor: "<< s->maximumSafenessFactor(grid);

    return 0;
}