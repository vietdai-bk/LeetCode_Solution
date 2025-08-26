#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<=i+nums[i];j++) {
                if (j < n) {
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        for (int x : dp) cout << x << " ";
        cout << endl;
        return !(dp[n-1] == INT_MAX);
    }
};
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxInd)
                return false;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};
*/
int main() {
    Solution solve;
    vector<int> nums = {3,2,1,0,4};
    bool isCanJump = solve.canJump(nums);
    cout << isCanJump;
    return 0;
}