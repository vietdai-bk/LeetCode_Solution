#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void setRowColZeroes(vector<vector<int>>& matrix, int j, string flag="row") {
        if (flag=="row") {
            for (int i=0;i<matrix[0].size();i++) {
                matrix[j][i] = 0;
            }
        }
        if (flag=="col") {
            for (int i=0;i<matrix.size();i++) {
                matrix[i][j] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[i].size();j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto row : rows) {
            setRowColZeroes(matrix, row, "row");
        }
        for (auto col : cols) {
            setRowColZeroes(matrix, col, "col");
        }
        for (auto& row : matrix) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution solve;
    solve.setZeroes(matrix);
}