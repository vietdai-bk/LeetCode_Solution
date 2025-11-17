#include <bits/stdc++.h>
using namespace std;

/*
1+2+3...+x = n;
<=> (x+1).x/2 = n
<=> x^2 + x + 1/4 = 2n + 1/4
<=> (x+1/2)^2 = 2n+1/4
<=> x+1/2 = sqrt(2n+1/4)
<=> x = sqrt(2n+1/4)-1/2
=> x = floor(x)
*/

class Solution {
public:
    int arrangeCoins(int n) {
        // cout << sqrt(2*n+1/4.0) - 1/2.0 << endl;
        return floor(sqrt(2*n+1/4.0)-1/2.0);
    }
};

int main() {
    const int n = 2;
    Solution solve;
    cout << solve.arrangeCoins(n);
}