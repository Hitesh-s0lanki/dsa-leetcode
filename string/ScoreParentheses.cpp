#include <iostream>

using namespace std;

class Solution {
public:
    int solve(string &s, int i, int j) {
        int result = 0, openBrac = 0;

        for (int k = i; k < j; k++) {
            openBrac += s[k] == '(' ? 1 : -1;

            if (openBrac == 0) {
                // no inner member
                if (k - i == 1)
                    result++;
                else
                    result += 2 * solve(s, i + 1, k);
                i = k + 1;
            }
        }

        return result;
    }

    int scoreOfParentheses(string s) {
        return solve(s, 0, s.length());
    }
};

int main() {
    string s = "(())";

    return 0;
}