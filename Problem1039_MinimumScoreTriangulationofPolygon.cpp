#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                dp[i][k] + dp[k][j] + A[i]*A[j]*A[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution solve;
    vector<int> A = {1,3,1,4,1,5};
    cout << solve.minScoreTriangulation(A);
}