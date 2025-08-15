#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend, b = divisor;
        long long res = 0;
        bool isPositive = (a>0 == b>0);
        if (dividend == INT_MIN) a = -(long long)dividend;
        else a = abs(dividend);
        if (divisor == INT_MIN) b = -(long long)divisor;
        else b = abs(divisor);
        while (b<=a) {
            int x = 1;
            while (b<<x < a) x++;
            res += 1<<(x-1);
            a -= b<<(x-1);
        }
        res = isPositive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return res;
    }
};

int main() {
    Solution solve;
    int dividend = INT_MIN, divisor = 1;
    int res = solve.divide(dividend, divisor);
    cout << res;
}