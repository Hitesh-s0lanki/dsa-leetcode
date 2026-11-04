// Time COmplexity -> OlogK

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<P, vector<P>, greater<P>> pq;

        // store the freq
        for (int i : nums)
            freq[i]++;

        // iterate over the map
        for (auto &it : freq) {
            int value = it.first;
            int freqz = it.second;

            pq.push({freqz, value});

            if (pq.size() > k)
                pq.pop();
        }

        // store in ans
        vector<int> result(k);
        k--;

        while (!pq.empty()) {
            result[k--] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};

int main() {
    return 0;
}