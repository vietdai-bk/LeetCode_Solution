#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int top=0, bottom=m-1;
        while (top <= bottom) {
            int row = top + (bottom-top)/2;
            if (matrix[row][n-1] == target) return true;
            if (matrix[row][n-1] < target) top = row+1;
            else bottom = row-1;
        }
        if (top > m-1) return false;
        cout << top << " ";
        int left=0, right = n-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (matrix[top][mid] == target) return true;
            if (matrix[top][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    const int target = 0;
    Solution solve;
    string res = solve.searchMatrix(matrix, target) ? "TRUE" : "FALSE";
    cout << res;
}