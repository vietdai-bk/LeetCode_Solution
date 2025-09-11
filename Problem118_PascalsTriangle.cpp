#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==1) return {{1}};
        if (numRows==2) return {{1},{1,1}};
        vector<vector<int>> res= {{1},{1,1}};
        for (int i=2;i<numRows;i++) {
            vector<int> oneRow;
            oneRow.push_back(1);
            for (int j=0;j<res[i-1].size()-1;j++) {
                int oneElement = res[i-1][j] + res[i-1][j+1];
                oneRow.push_back(oneElement);
            }
            oneRow.push_back(1);
            res.push_back(oneRow);
        }
        return res;
    }
};

int main() {
    const int numRows=10;
    Solution solve;
    vector<vector<int>> res = solve.generate(numRows);
    for (auto& row : res) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}