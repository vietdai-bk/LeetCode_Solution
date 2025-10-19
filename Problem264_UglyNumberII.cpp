#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        int k=0,p=0,q=0;
        dp[0]=1;
        for (int i=1;i<n;i++) {
            dp[i]=min({dp[k]*2, dp[p]*3, dp[q]*5});
            if (dp[i]==dp[k]*2) k+=1;
            if (dp[i]==dp[p]*3) p+=1;
            if (dp[i]==dp[q]*5) q+=1;
        }
        return dp[n-1];
    }
};

int main() {
    Solution solve;
    const int n=10;
    cout << solve.nthUglyNumber(n);
    cout << endl;
}