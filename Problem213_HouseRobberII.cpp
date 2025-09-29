#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robber(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return nums[0];
        if (n<3) return nums[0] > nums[1] ? nums[0] : nums[1];
        int dp[nums.size()];
        int flag1=0, flag2=2;
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2]+nums[0];
        for (int i=3;i<n-1;i++) {
            dp[i] = max(nums[i]+dp[i-2], nums[i]+dp[i-3]);
        }
        return dp[n-2] > dp[n-3] ? dp[n-2] : dp[n-3];
    }
    int rob(vector<int>& nums) {
        int temp1 = robber(nums);
        reverse(nums.begin(), nums.end());
        int temp2 = robber(nums);
        return temp1 > temp2 ? temp1 : temp2;
    }
};

int main() {
    vector<int> nums = {2,3,2};
    Solution solve;
    cout << solve.rob(nums);
}