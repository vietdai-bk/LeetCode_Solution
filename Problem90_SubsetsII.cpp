#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneSub;
    void backtrack(int start, vector<int>& nums) {
        res.push_back(oneSub);
        for (int i=start;i<nums.size();i++) {
            if (i > start && nums[i]==nums[i-1]) continue;
            oneSub.push_back(nums[i]);
            backtrack(i+1, nums);
            oneSub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {4,4,4,1,4};
    vector<vector<int>> res = solve.subsetsWithDup(nums);
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}