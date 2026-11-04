#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int result = 0;
        int openBrack = 0;

        for (int i = 0; i < s.length(); i++) {
            openBrack += s[i] == '(' ? 1 : -1;

            if (openBrack < 0) {
                result += (-1 * openBrack);
                openBrack = 0;
            }
        }

        if (openBrack != 0) {
            result += abs(openBrack);
            openBrack = 0;
        }

        return result;
    }
};

int main() {
    string s = "())))";

    Solution st;
    cout << st.minAddToMakeValid(s);

    return 0;
}