#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};

int main() {
    Solution solve;
    const int k = 38;
    cout << solve.addDigits(k);
}