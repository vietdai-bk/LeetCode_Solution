#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneCombination;
    void backtrack(vector<int>& candidates, int target, int start, int curSum) {
        if (curSum == target) {
            res.push_back(oneCombination);
            return;
        }
        if (curSum > target) return;
        for (int i=start;i<candidates.size();i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            oneCombination.push_back(candidates[i]);
            backtrack(candidates, target, i+1, curSum+candidates[i]);
            oneCombination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }
};
int main() {
    Solution solve;
    vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,33,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,44,4,4,4,5,5,5,5,5,5,5,5,5,5,5,49,5,5,5,5,6,6,6,6};
    const int target = 29;
    vector<vector<int>> res = solve.combinationSum2(candidates, target);
    for (auto &row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}