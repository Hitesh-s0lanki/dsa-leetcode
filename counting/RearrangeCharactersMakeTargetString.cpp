#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int rearrangeCharacters(string s, string target) {
        vector<int> sFreq(26, 0);
        vector<int> targetFreq(26, 0);

        for (char ch : s) {
            sFreq[ch - 'a']++;
        }

        for (char ch : target) {
            targetFreq[ch - 'a']++;
        }

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (targetFreq[i] > 0) {
                ans = min(ans, sFreq[i] / targetFreq[i]);
            }
        }

        return ans;
}

int main() {

    // string s = "ilovecodingonleetcode", target = "code";
    string s = "abcba", target = "abc";

    cout<<rearrangeCharacters(s, target);

    return 0;
}