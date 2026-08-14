// 3090. Maximum Length Substring With Two Occurrences
// each character should be occured 2
#include <iostream>

using namespace std;

int maximumLengthSubstring(string s) {
    int n = s.length();

    // map of the element present
    vector<int> mp(26, 0);

    int result = 0;
    int i = 0;
    int j = 0;

    while (j < n) {
        int curr = s[j];
        mp[curr - 'a']++;

        while (mp[curr - 'a'] > 2) {
            mp[s[i] - 'a']--;
            i++;
        }

        result = max(result, j - i + 1);
        j++;
    }

    return result;
}

int main() {
    cout << maximumLengthSubstring("bcbbbcba");

    return 0;
}