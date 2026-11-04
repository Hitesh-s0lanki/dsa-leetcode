#include <iostream>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);

        priority_queue<pair<char, int>,
                       vector<pair<char, int>>, Compare>
            pq;

        for (char ch : s)
            freq[ch]++;

        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0)
                pq.push({char(i), freq[i]});
        }

        string result = "";

        while (!pq.empty()) {
            pair<char, int> ch = pq.top();
            pq.pop();

            for (int i = 0; i < ch.second; i++)
                result.push_back(ch.first);
        }

        return result;
    }
};

int main() {
    return 0;
}