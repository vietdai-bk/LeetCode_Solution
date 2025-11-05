#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int n_i = sqrt(num);
        double n_d = sqrt(double(num));
        if (n_d-n_i==0) return true;
        return false;
    }
};

int main() {
    Solution solve;
    const int num=16;
    cout << solve.isPerfectSquare(num);
}