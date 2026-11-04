#include <iostream>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> pq;

        for (int i : piles)
            pq.push(i);

        while (k != 0) {
            int top = pq.top();
            pq.pop();

            pq.push(top - floor(top / 2));

            k--;
        }

        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};

int main() {
    return 0;
}