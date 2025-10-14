#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0) return {};
        if (nums.size()==1) return {to_string(nums[0])};
        vector<string> res;
        string s=to_string(nums[0]);
        for (int i=1;i<nums.size();i++) {
            if (nums[i]==nums[i-1]+1) continue;
            else {
                if (stoi(s)!=nums[i-1]) {
                    s+="->" + to_string(nums[i-1]);
                }
                res.push_back(s);
                s=to_string(nums[i]);
            }
        }
        if (nums[nums.size()-1]==nums[nums.size()-2]+1) s+="->" + to_string(nums[nums.size()-1]);
        res.push_back(s);
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {-1};
    vector<string> res = solve.summaryRanges(nums);
    for (string s : res) cout << s << " ";
}