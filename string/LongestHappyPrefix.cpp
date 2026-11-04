#include <iostream>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();

        int len = 0;
        int i = 1;

        vector<int> lps(n, 0);

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};
int main() {
    string s = "babbb";

    Solution st;
    cout << st.longestPrefix(s);

    return 0;
}