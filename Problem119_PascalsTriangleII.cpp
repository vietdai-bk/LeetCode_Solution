#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long factorial(int n) {
        if (n<2) return 1;
        long long fac[n+1];
        fac[1]=1;
        for (int i=2;i<=n;i++) {
            fac[i] = i*fac[i-1];
        }
        return fac[n];
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        int rows = rowIndex > 20 ? 20 : rowIndex;
        for (int i=0;i<=rows;i++) {
            int temp = factorial(rows)/(factorial(i)*factorial(rows-i));
            res.push_back(temp);
        }
        for (int i=21;i<=rowIndex;i++) {
            vector<int> temp(i+1, 0);
            temp[0]=1, temp[i]=1;
            for (int j=1;j<=i-1;j++) {
                temp[j] = res[j-1] + res[j];
            }
            res = temp;
        }
        return res;
    }
};

int main() {
    Solution solve;
    const int n = 32;
    cout << solve.factorial(33) << endl;
    for (int i=0;i<=n;i++) {
        vector<int> res = solve.getRow(i);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    vector<int> res = solve.getRow(n);
    for (int x : res) cout << x << " ";
}