#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        int k = 0;
        vector<vector<int>> res;
        for (int i=0;i<n;i++) {
            vector<int> temp;
            for (int j=0;j<n;j++) {
                temp.push_back(0);
            }
            res.push_back(temp);
        }
        while (left <= right && top <= bottom) {
            for (int i=left;i<=right;i++) {
                k+=1;
                res[top][i] = k;
            }
            top+=1;
            for (int i=top;i<=bottom;i++) {
                k+=1;
                res[i][right] = k;
            }
            right-=1;
            if (top <= bottom) {
                for (int i=right;i>=left;i--) {
                    k+=1;
                    res[bottom][i] = k;
                }
                bottom-=1;
            }
            if (left<=right) {
                for (int i=bottom;i>=top;i--) {
                    k+=1;
                    res[i][left] = k;
                }
                left+=1;
            }
        }
        return res;
    }
};
int main() {
    Solution solve;
    const int n = 3;
    vector<vector<int>> res = solve.generateMatrix(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << res[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}