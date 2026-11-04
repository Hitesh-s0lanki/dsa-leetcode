#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // length of the string
        int n = s.length();
        int result = 0;

        int openBrac = 0;

        for (int i = 0; i < n; i++) {
            if (openBrac < 0 && s[i] == '(') {
                result += abs(openBrac) / 2;
                openBrac = 0;
            }

            openBrac += s[i] == '(' ? 2 : -1;
        }

        if (openBrac < 0) {
            result += abs(openBrac) / 2;
            openBrac = 0;
        }

        return result += openBrac;
    }
};

int main() {
    string s = ")))))))";

    Solution st;
    cout << st.minInsertions(s);

    return 0;
}