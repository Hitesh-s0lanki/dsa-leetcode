#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string result = "";
    vector<int> freq;  // counts for one half only
    char middle = 0;   // fixed centre character when n is odd
    int halfLen = 0;

    string build(string &half) {
        string p = half;
        if (middle)
            p.push_back(middle);
        p.append(half.rbegin(), half.rend());
        return p;
    }

    bool solve(string &curr, string &target, int i, bool greater) {
        if (i == halfLen) {
            string cand = build(curr);
            if (cand > target) {
                result = cand;
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

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> cnt(26, 0);
        for (char ch : s)
            cnt[ch - 'a']++;

        freq.assign(26, 0);
        int odd = 0;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] & 1) {
                odd++;
                middle = 'a' + c;
            }
            freq[c] = cnt[c] / 2;
        }

        // a palindrome allows one odd count only when n is odd
        if (odd > (n & 1))
            return "";

        halfLen = n / 2;

        string curr;

        solve(curr, target, 0, false);

        return result;
    }
};

int main() {
    Solution s1, s2, s3, s4;
    cout << "[" << s1.lexPalindromicPermutation("baba", "abba") << "]" << endl;  // baab
    cout << "[" << s2.lexPalindromicPermutation("baba", "bbaa") << "]" << endl;  // ""
    cout << "[" << s3.lexPalindromicPermutation("abc", "abb") << "]" << endl;    // ""
    cout << "[" << s4.lexPalindromicPermutation("aac", "abb") << "]" << endl;    // aca
    return 0;
}
