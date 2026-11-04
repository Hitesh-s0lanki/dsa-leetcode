#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> compute_lps(string &pattern, int m) {
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
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

        return lps;
    }

    vector<int> search(string &pattern, string &txt) {
        int m = pattern.length();
        int n = txt.length();

        vector<int> result;

        // Step 1: compute the LPS
        vector<int> lps = compute_lps(pattern, m);

        int i = 0, j = 0;

        while (i < n) {
            if (pattern[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }
};

int main() {
    string pattern = "geek";
    string txt = "geeksforgeeks";

    Solution st;
    vector<int> ans = st.search(pattern, txt);

    for (int i : ans)
        cout << i << "\t";

    return 0;
}
