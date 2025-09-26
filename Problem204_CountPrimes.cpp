#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<bool> isPrimes(n, true);
        int res=0;
        for (int i=2;i<n;i++) {
            if (isPrimes[i]) {
                for (int j=i*2;j<n;j+=i) {
                    isPrimes[j] = false;
                }
            }
        }
        for (int i=2;i<n;i++) {
            if (isPrimes[i]) {
                cout << isPrimes[i] << " ";
                res+=1;
            }
        }
        return res;
    }
};

int main() {
    Solution solve;
    const int n = 75;
    cout << solve.countPrimes(n);
}