#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n==2) return 2;
        if (n==1) return 1;
        int res;
        int dp1 = 1, dp2 = 2;
        for (int i=3;i<=n;i++) {
            res = dp1 + dp2;
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};
int main() {
    Solution solve;
    const int n = 10;
    int res = solve.climbStairs(n);
    cout << res;
    return 0;
}