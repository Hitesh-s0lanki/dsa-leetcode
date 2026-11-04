#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>> &knowledge) {
        int n = s.length();
        string result;

        unordered_map<string, string> mp;

        for (vector<string> elem : knowledge)
            mp[elem[0]] = elem[1];

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }

                if (mp.find(key) != mp.end())
                    result += mp[key];
                else
                    result.push_back('?');

            } else
                result.push_back(s[i]);
        }

        return result;
    }
};

int main() {
    return 0;
}