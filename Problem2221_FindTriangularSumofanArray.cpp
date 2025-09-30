#include <bits/stdc++.h>
using namespace std;

// AC nhưng chưa tối ưu bộ nhớ
// class Solution {
// public:
//     vector<vector<int>> triangle;
//     void recursion(vector<int> nums, int k) {
//         if (nums.size()==1) return;
//         triangle.push_back({});
//         for (int i=0;i<nums.size()-1;i++) {
//             triangle[k].push_back((nums[i]+nums[i+1])%10);
//         }
//         recursion(triangle[k], k+1);
//     }
//     int triangularSum(vector<int>& nums) {
//         if (nums.size()==1) return nums[0];
//         recursion(nums, 0);
//         return triangle[nums.size()-2][0];
//     }
// };

// AC bộ nhớ O(n), time O(n^2) => nhanh hơn recursion (chưa biết vì sao:))
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> dp=nums;
        for (int len = nums.size(); len > 1; --len) {
            for (int i = 0; i < len-1; i++) {
                dp[i] = (dp[i] + dp[i+1]) % 10;
            }
        }
        return dp[0];
    }
};

int main() {
    vector<int> nums;
    for (int i=1;i<=1000;i++) nums.push_back(i);
    Solution solve;
    cout << solve.triangularSum(nums);
}