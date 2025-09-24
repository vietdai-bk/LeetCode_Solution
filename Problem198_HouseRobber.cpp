#include <bits/stdc++.h>
using namespace std;

// ý tưởng: số tiền tối đa tại nhà i = max(nums[i]+dp[i-2], nums[i]+dp[i-3]), trong đó dp[i-2] max tại i-2, dp[i-3] max tại i-3;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return nums[0];
        if (n<3) return nums[0] > nums[1] ? nums[0] : nums[1];
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0], dp[1] = nums[1], dp[2] = nums[0]+nums[2];
        for (int i=3;i<n;i++) {
            dp[i] = max(nums[i]+dp[i-2], nums[i]+dp[i-3]);
        }
        // for (int x : dp) cout << x << " ";
        return dp[n-1] > dp[n-2] ? dp[n-1] : dp[n-2];
    }
};

int main() {
    Solution solve;
    vector<int> nums = {400,399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,302,301};
    cout << solve.rob(nums);
}