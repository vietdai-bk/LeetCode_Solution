#include <bits/stdc++.h>
using namespace std;

// TLE: quá chậm O(n^3)
// class Solution {
// public:
//     vector<int> checkNum;
//     int res=0;
//     void backtrack(vector<int> nums, int start) {
//         if (checkNum.size()==3 && checkNum[2]<checkNum[1]+checkNum[0]) {
//             res+=1;
//             return;
//         }
//         for (int i=start;i<nums.size();i++) {
//             checkNum.push_back(nums[i]);
//             backtrack(nums, i+1);
//             checkNum.pop_back();
//         }
//     }
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         backtrack(nums, 0);
//         return res;
//     }
// };

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res=0;
        for (int k=n-1;k>=2;k--) {
            int i=0, j=k-1;
            while (i<j) {
                if (nums[k]<nums[i]+nums[j]) {
                    res+=(j-i);
                    j-=1;
                }
                else {
                    i+=1;
                }
            } 
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {4,2,3,4};
    cout << solve.triangleNumber(nums);
}