#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n,0);
        int j=1;
        int k=n-1;
        for (int i=0;i<n/2;i++) {
            res[i]=j;
            res[k]=-j;
            j+=1;
            k-=1;
        }
        return res;
    }
};

int main() {
    const int n = 10;
    Solution solve;
    vector<int> res = solve.sumZero(n); 
    for (int x : res) cout << x << " ";
}