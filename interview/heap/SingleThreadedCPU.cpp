#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int n = tasks.size();

        vector<int> result;
        vector<vector<int>> sortedTasks;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < n; i++) {
            int startTime = tasks[i][0];
            int endTime = tasks[i][1];

            sortedTasks.push_back({startTime, endTime, i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        int currentTime = 0;
        int idx = 0;

        while (idx < n || !pq.empty()) {
            // for the start time skips
            if (pq.empty() && currentTime < sortedTasks[idx][0])
                currentTime = sortedTasks[idx][0];

            while (idx < n && sortedTasks[idx][0] <= currentTime) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int, int> currTask = pq.top();
            pq.pop();

            currentTime += currTask.first;
            result.push_back(currTask.second);
        }

        return result;
    }
};

int main() {
    return 0;
}