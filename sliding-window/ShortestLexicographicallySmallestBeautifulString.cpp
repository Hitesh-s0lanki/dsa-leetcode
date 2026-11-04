#include <iostream>

using namespace std;

string shortestBeautifulSubstring(string s, int k) {
    int n = s.length();

    // answer will be store in this
    string result = "";

    // initial values
    int i = 0, j = 0, ones = 0;

    while (j < n) {
        if (s[j] == '1')
            ones++;

        // sink the window
        while (ones > k || s[i] == '0') {
            if (s[i] == '1')
                ones--;
            i++;
        }

        if (ones == k) {
            string temp = s.substr(i, j - i + 1);
            if (result.empty() || result.length() > j - i + 1 || (temp.length() == result.length() && temp < result))
                result = temp;
        }

        j++;
    }

    return result;
}

int main() {
    string s = "100011001";
    int k = 3;

    cout << shortestBeautifulSubstring(s, k);

    return 0;
}