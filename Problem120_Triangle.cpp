#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp={{triangle[0][0]}};
        for (int i=1;i<n;i++) {
            int m=triangle[i].size();
            vector<int> temp(m,0);
            dp.push_back(temp);
            for (int j=0;j<m;j++) {
                if (j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if (j==m-1) dp[j][j] = dp[i-1][j-1] + triangle[i][j];
                else dp[i][j] = min(triangle[i][j]+dp[i-1][j-1], triangle[i][j]+dp[i-1][j]);
            }
        }    
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    Solution solve;
    vector<vector<int>> triangle={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << solve.minimumTotal(triangle);
}