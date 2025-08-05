#include <bits/stdc++.h>
using namespace std;
// target + complement + nums[j] = 0, target = nums[i]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> results;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            vector<int> numResult;
            int target = nums[i];
            unordered_map<int,int> numIndex;
            for (int j=i+1;j<n;j++) {
                int complement = -nums[j] - target;
                if (numIndex.find(complement)!=numIndex.end()) {
                    numResult.push_back(target);
                    numResult.push_back(nums[j]);
                    numResult.push_back(complement);
                    sort(numResult.begin(),numResult.end());
                    results.insert(numResult);
                    numResult.clear();
                }
                numIndex[nums[j]] = j;
            }
        }
        vector<vector<int>> ans(results.begin(),results.end());
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
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());   // --> O(nlogn)
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i>0 and arr[i]==arr[i-1])continue;

            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];

                //3 conditions ayengi
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    //we got our triplet
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    while(j<k and arr[j]==arr[j-1])j++;
                    while(j<k and arr[k]==arr[k+1])k--;
                }
            }
        }
        
        return ans;
    }
};
*/