#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i=0;i<n;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for (auto& row : matrix) {
            for (int x : row) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    Solution solve;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    solve.rotate(matrix);
}