#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneCombine;
    void backtrack(int pos, int n, int k, int cur) {
        if (pos >= k) {
            res.push_back(oneCombine);
            return;
        }
        for (int i=cur;i<=n;i++) {
            oneCombine.push_back(i);
            backtrack(pos+1, n, k, i+1);
            oneCombine.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int pos=0, cur=1;
        backtrack(pos, n, k, cur);
        return res;
    }
};

int main() {
    const int n=10, k=4;
    Solution solve;
    vector<vector<int>> res = solve.combine(n, k);
    for (auto &row : res) {
        for (int x : row) cout << x <<" ";
        cout << endl;
    }
}