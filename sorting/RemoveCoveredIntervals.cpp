#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        auto lamba = [](vector<int> vect1, vector<int> vect2){
            if(vect1[0] == vect2[0]){
                return vect1[1] > vect2[1];
            }

            return vect1[0] < vect2[0];
        };

        sort(intervals.begin(), intervals.end(), lamba);

        int cnt = 1;
        int lastIntervalEnd = intervals[0][1];

        // iterate over all the interval
        for(int i = 1; i < n; i++){

            if (lastIntervalEnd >= intervals[i][1]) continue;

            lastIntervalEnd = intervals[i][1];
            cnt++;

        }

        return cnt;
    }
};

int main() {

    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};

    Solution s;
    int ans = s.removeCoveredIntervals(intervals);

    cout<<ans;

    return 0;
}