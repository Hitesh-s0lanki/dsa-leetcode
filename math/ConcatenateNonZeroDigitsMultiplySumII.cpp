#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // length of the string
        int n = s.length();

        // prefix sum 
        vector<long> prefixSum(n, 0);
        // pre non zero number
        vector<long> preNonZeroNumber(n, 0);
        // pre count
        vector<long> preCount(n, 0);

        // single pass for the all the required values 
        for(int i = 0; i < n; i++){
            int digit = s[i] - '0';

            if (i > 0){
                prefixSum[i] = prefixSum[i - 1];
                preNonZeroNumber[i] = preNonZeroNumber[i - 1];
                preCount[i] = preCount[i-1];
            } 

            if (digit != 0){
                preCount[i]++;
                preNonZeroNumber[i] = ((preNonZeroNumber[i] * 10) % mod + digit) % mod;
            }

            prefixSum[i] += digit;
        }

        // power value for 10, 100, ... 1n
        vector<long> power(n + 1, 1);
        for(int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 10) % mod;
        
        // evaluate the final outcome
        int m = queries.size();
        vector<int> ans(m);

        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            long len = preCount[r] - ((l > 0) ? preCount[l - 1] : 0);
            long x = preNonZeroNumber[r];
            if (l > 0) {
                x = (x - (preNonZeroNumber[l - 1] * power[(int)len] % mod) + mod) % mod;
            }

            long sum = (prefixSum[r] - ((l > 0) ? prefixSum[l - 1] : 0)) % mod;
            ans[i] = (int) ((x * sum) % mod) % mod;
        }

        return ans;
    }
};

void print(vector<int>& ans){
    for(int i:ans)
        cout<<i<<", ";
    cout<<endl;
}

int main() {

    string  s = "10203004";
    vector<vector<int>> queries = {{0,7}, {1, 3}, {4, 6}};

    Solution *sol = new Solution();

    vector<int> ans = sol->sumAndMultiply(s, queries); 
    print(ans);

    return 0;
}