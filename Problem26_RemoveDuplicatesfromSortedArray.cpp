#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> se;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            se.insert(nums[i]);
        }
        return se.size();
    }
};
int main() {
    Solution solve;
    vector<int> nums = {1,1,2};
    cout << solve.removeDuplicates(nums);
}
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
*/