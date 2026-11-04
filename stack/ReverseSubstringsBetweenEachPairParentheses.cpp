#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string result;

        for (char ch : s) {
            if (ch == '(')
                openParenthesesIndices.push(result.length());
            else if (ch == ')') {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();

                reverse(result.begin() + start, result.end());
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};

int main() {
    string s = "(ed(et(oc))el)";

    Solution st;

    cout << st.reverseParentheses(s);
    return 0;
}