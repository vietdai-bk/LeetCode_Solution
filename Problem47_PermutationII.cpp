#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> onePerUnique;
    bool used[8] = {false};
    void backtrack(vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            res.push_back(onePerUnique);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            onePerUnique.push_back(nums[i]);
            backtrack(nums, pos+1);
            onePerUnique.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = solve.permuteUnique(nums);
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}