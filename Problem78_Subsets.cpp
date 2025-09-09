#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneSubset;
    void backtrack(int start, vector<int>& nums) {
        res.push_back(oneSubset);
        for (int i=start;i<nums.size();i++) {
            oneSubset.push_back(nums[i]);
            backtrack(i+1, nums);
            oneSubset.pop_back();
        }
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solve;
    vector<vector<int>> res = solve.subsets(nums);
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}