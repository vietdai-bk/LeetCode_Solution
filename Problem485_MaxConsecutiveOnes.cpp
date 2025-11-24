#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        if (nums[0]==1) dp[0]=1;
        else dp[0]=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]==1) dp[i] = dp[i-1]+nums[i];
            else dp[i] = 0;
        }
        return *max_element(dp, dp+sizeof(dp)/sizeof(dp[0]));
    }
};

int main() {
    vector<int> nums = {1,0,1,1,1};
    Solution solve;
    cout << solve.findMaxConsecutiveOnes(nums);
}