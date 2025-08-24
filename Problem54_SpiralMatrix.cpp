#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        vector<int> res;
        while (left <= right && top <= bottom) {
            for (int i=left;i<=right;i++) {
                res.push_back(matrix[top][i]);
            }
            top+=1;
            for (int i=top;i<=bottom;i++) {
                res.push_back(matrix[i][right]);
            }
            right-=1;
            if (top <= bottom) {
                for (int i=right;i>=left;i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom-=1;
            }
            if (left <= right) {
                for (int i=bottom;i>=top;i--) {
                    res.push_back(matrix[i][left]);
                }
                left+=1;
            }
        }
        return res;
    }
};
int main() {
    Solution solve;
    vector<vector<int>> nums = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> res = solve.spiralOrder(nums);
    for (int x : res) cout << x << " ";
    return 0;
}