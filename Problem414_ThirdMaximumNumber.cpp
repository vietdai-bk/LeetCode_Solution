#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = 1;
        for (int i=nums.size()-2;i>=0;i--) {
            if (nums[i]!=nums[i+1]) diff+=1;
            if (diff==3) return nums[i];
        }
        return nums[nums.size()-1];
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1};
    cout << solve.thirdMax(nums);
}