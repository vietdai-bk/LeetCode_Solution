#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> onePermutation;
    void backtrack(vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            res.push_back(onePermutation);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (find(onePermutation.begin(), onePermutation.end(), nums[i]) == onePermutation.end()) {
                onePermutation.push_back(nums[i]);
                backtrack(nums, pos+1);
                onePermutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = solve.permute(nums);
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}