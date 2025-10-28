#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int count=0;
        for (int i=0;i<=n;i++) {
            int m=i;
            while (m!=0) {
                if (m&1) {
                    count+=1;
                }
                m=m>>1;
            }
            res.push_back(count);
            count=0;
        }
        return res;
    }
};

int main() {
    const int n=5;
    Solution solve;
    vector<int> res = solve.countBits(n);
    for (int x : res) cout << x << " ";
}