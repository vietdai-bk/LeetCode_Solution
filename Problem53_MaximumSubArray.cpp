#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max(int a, int b) {
        return (a >= b) ? a : b; 
    }
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0], maxSubArray = nums[0];
        for (int i=1;i<nums.size();i++) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSubArray = max(currentMax, maxSubArray);
        }
        return maxSubArray;
    }
};
int main() {
    Solution solve;
    vector<int> nums = {5,4,-1,7,8};
    cout << solve.maxSubArray(nums);
    return 0;
}