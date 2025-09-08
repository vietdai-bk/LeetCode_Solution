#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> countArr(3, 0);
        for (int i=0;i<nums.size();i++) {
            countArr[nums[i]]+=1;
        }
        int k=0;
        for (int i=0;i<countArr.size();i++) {
            while (countArr[i]--) {
                nums[k++]=i;
            }
        }
        for (int x : nums) cout << x << " ";
    }
};

int main() {
    vector<int> nums = {2,2,2,1,1,0,0,1,0,1,0,2,1,0,2,1,0,2,1,1};
    Solution solve;
    solve.sortColors(nums);
}