#include <bits/stdc++.h>
using namespace std;
// -4 -1 1 2 
// target = 1
// nums[i]=-4, nums[j]=-1, nums[k]=2 => sum = -3 < target => tăng j và min = sum;
// nums[j] = 1 => sum = -1 < target => tăng j; j=k; => tăng i
// xét < > là xét abs tới target
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for (int i=0;i<n;i++) {
            int j=i+1, k=n-1;
            while (j<k) {
                int sum = nums[i] + nums[k] + nums[j];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;
                }
                ans = (abs(sum-target) < abs(ans-target)) ? sum : ans;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {0,0,0};
    int target = 10000;
    Solution solve;
    int results = solve.threeSumClosest(nums, target);
    cout << results;
}