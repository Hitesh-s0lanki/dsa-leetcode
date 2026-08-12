#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        // all side 
        int left = 0;
        int right = n - 1;  
        int top = 0;
        int bottom = m - 1;

        for (int i = 0; i < m * n; i++) {
            if (top <= bottom) {
                for (int j = left; j <= right; j++) {
                    ans.push_back(mat[top][j]);
                }
                top++;
            }

            if (left <= right) {
                for (int j = top; j <= bottom; j++) {
                    ans.push_back(mat[j][right]);
                }
                right--;
            }

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(mat[bottom][j]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    ans.push_back(mat[j][left]);
                }
                left++;
            }
        }

        return ans;

    }
};

void print1D(vector<int> ans){
    for (int i = 0; i< ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
}

void print2D(vector<vector<int>> ans){
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    print2D(mat);

    Solution *obj = new Solution();
    vector<int> ans = obj->spirallyTraverse(mat);

    print1D(ans);


    return 0;
}