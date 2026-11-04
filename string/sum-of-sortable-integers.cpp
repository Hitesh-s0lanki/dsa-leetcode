#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> compute_lps(vector<int> &pattern, int m) {
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

    bool search(vector<int> &pattern, vector<int> &txt) {
        int m = pattern.size();
        int n = txt.size();

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
                return true;
            } else if (i < n && pattern[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    bool isRotation(vector<int> &vec1, vector<int> &vec2) {
        vector<int> txt = vec2;
        txt.insert(end(txt), begin(vec2), end(vec2));
        return search(vec1, txt);
    }

    int sortableIntegers(vector<int> &nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(begin(nums) + start, begin(nums) + start + k);
                vector<int> vec2(begin(sorted) + start,
                                 begin(sorted) + start + k);

                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                result += k;
        }

        return result;
    }
};

int main() {
    return 0;
}