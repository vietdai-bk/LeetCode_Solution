#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=0) {
                swap(nums[i], nums[l++]);
            }
        }
        for (int x : nums) cout << x << " ";
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution solve;
    solve.moveZeroes(nums);
}