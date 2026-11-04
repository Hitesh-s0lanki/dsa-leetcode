#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string sortedString = s;
        int result = 0;

        sort(sortedString.begin(), sortedString.end());

        unordered_map<char, int>

            for (int i = 0; i <)

                return result;
    }
};

int main() {
    string s = "dog";

    Solution st;
    cout << st.minOperations(s);

    return 0;
}