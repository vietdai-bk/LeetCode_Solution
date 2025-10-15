#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0) return false;
        return !(n&(n-1));     
    }
};

int main() {
    const int n=6;
    Solution solve;
    cout << solve.isPowerOfTwo(n);
}