#include <bits/stdc++.h>
using namespace std;
// DP -> O(n^2)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MAX);
//         dp[0] = 0;
//         for (int i=0;i<n;i++) {
//             for (int j=i+1;j<=i+nums[i];j++) {
//                 if (j < n) {
//                     dp[j] = min(dp[j], dp[i] + 1);
//                 }
//             }
//         }
//         for (int x : dp) cout << x <<" ";
//         cout <<endl;
//         return dp[n-1];
//     }
// };

// Greedy -> O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1,2,1,1,1};
    cout << solve.jump(nums);
    return 0;
}