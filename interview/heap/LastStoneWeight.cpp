#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq;

        for (auto i : stones)
            pq.push(i);

        while (pq.size() > 1 && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (abs(x - y) != 0)
                pq.push(abs(x - y));
        }

        return pq.top();
    }
};

int main() {
    return 0;
}