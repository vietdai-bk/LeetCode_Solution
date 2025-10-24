#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> oneRes;
    void backtrack(int start, int sum, int k, int n) {
        if (oneRes.size()==k) {
            if (sum==n) res.push_back(oneRes);
            return;
        }
        for (int i=start;i<=9;i++) {
            oneRes.push_back(i);
            sum+=i;
            backtrack(i+1, sum, k, n);
            oneRes.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        backtrack(1, sum, k, n);
        return res;
    }
};

int main() {
    const int k=9, n=45;
    Solution solve;
    vector<vector<int>> res=solve.combinationSum3(k, n);
    for (auto &p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    } 
}