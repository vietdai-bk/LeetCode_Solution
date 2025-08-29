class Solution {
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