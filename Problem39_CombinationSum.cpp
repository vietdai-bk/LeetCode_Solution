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

        for (int i = start; i < candidates.size(); i++) {
            oneCombination.push_back(candidates[i]);
            backtrack(candidates, target, i, curSum + candidates[i]); 
            oneCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return res;
    }
};

// Code fail
// class Solution {
// public:
//     set<vector<int>> res;
//     vector<int> oneCombination;
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int sum = accumulate(oneCombination.begin(), oneCombination.end(), 0);
//         if (sum > target) return {{}};
//         if (sum == target) {
//             sort(oneCombination.begin(), oneCombination.end());
//             res.insert(oneCombination);
//             return {{}};
//         }
//         for (int i=0;i<candidates.size();i++) {
//             oneCombination.push_back(candidates[i]);
//             combinationSum(candidates, target);
//             oneCombination.pop_back();
//         }
//         vector<vector<int>> v(res.begin(), res.end());
//         return v;
//     }
// };

int main() {
    Solution solve;
    vector<int> candidates = {7,3,2};
    const int target = 18;
    vector<vector<int>> res = solve.combinationSum(candidates, target);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}