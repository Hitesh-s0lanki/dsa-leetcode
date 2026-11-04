#include <iostream>

using namespace std;

class Solution {
public:
    string result = "";
    vector<int> freq;

    bool solve(string &curr, string &target, int i, bool greater) {
        if (i == target.length()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;

            if (greater == false && ch < target[i])
                continue;

            curr.push_back(ch);
            freq[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, target, i + 1, isGreater)) {
                return true;
            }

            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        freq.assign(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string curr;

        solve(curr, target, 0, false);

        return result;
    }
};

int main() {
    return 0;
}