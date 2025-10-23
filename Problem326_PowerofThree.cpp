#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        int largest = pow(3, 19); // vì n<=2^31-1
        if (largest%n==0) return true;
        return false;
    }
};

int main() {
    Solution solve;
    const int n = 0;
    cout << solve.isPowerOfThree(n);
}