#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int res=0, k=31;
        while (n!=0) {
            res += (n&1)*pow(2, k);
            k-=1;
            n>>=1;
        }
        return res;
    }
};

int main() {
    int n = 2147483644;
    Solution solve;
    cout << solve.reverseBits(n);
}