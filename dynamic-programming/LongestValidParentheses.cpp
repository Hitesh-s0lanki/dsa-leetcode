#include <iostream>

using namespace std;

class Solution {
public:
    int result = 0;

    void solve(string &s, int i, int openBrack, int size) {
        if (i >= s.length())
            return;

        openBrack += (s[i] == '(' ? 1 : -1);

        // invalid substring, restart from next position
        if (openBrack < 0) {
            solve(s, i + 1, 0, 0);
            return;
        }

        size++;

        // valid substring
        if (openBrack == 0)
            result = max(result, size);

        // continue current substring
        solve(s, i + 1, openBrack, size);

        // start a new substring from next index
        solve(s, i + 1, 0, 0);
    }

    int longestValidParentheses(string s) {
        result = 0;
        solve(s, 0, 0, 0);
        return result;
    }
};
int main() {
    string s = "()(()";

    Solution st;

    cout << st.longestValidParentheses(s);

    return 0;
}