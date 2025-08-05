#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end()); // ->O(nlogn)
        for (int i=0;i<n;i++) {
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1, k = n-1;
            while (j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum>0) {
                    k--;
                }
                else if (sum<0) {
                    j++;
                }
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (j<k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j<k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solve;
    vector<vector<int>> results = solve.threeSum(nums);
    for (int i=0;i<results.size();i++) {
        int n = results[i].size();
        for (int j=0;j<n;j++) {
            cout << results[i][j] << " ";
        }
        cout <<endl;
    }
}