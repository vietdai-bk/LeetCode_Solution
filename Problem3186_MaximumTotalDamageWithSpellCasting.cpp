#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> sum;
        for (int p : power) sum[p] += p;

        vector<int> keys;
        for (auto it = sum.begin(); it != sum.end(); ++it) {
            keys.push_back(it->first);
        }

        int n = keys.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long take = sum[keys[i]];
            int j = i - 1;
            while (j >= 0 && keys[i] - keys[j] <= 2) j--;
            if (j >= 0) take += dp[j];
            long long skip = (i > 0) ? dp[i - 1] : 0;
            dp[i] = max(skip, take);
        }

        return dp.back();
    }
};

int main() {
    vector<int> powers = {1,1,3,4};
    Solution solve;
    cout << solve.maximumTotalDamage(powers);
}