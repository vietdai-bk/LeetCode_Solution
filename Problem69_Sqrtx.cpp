#include <bits/stdc++.h>
#define ll long long

using namespace std;
class Solution {
public:
    ll mySqrt(ll x) {
        if (x==0) return 0;
        double res=x;
        double a = x;
        for (int i=0;i<10000;i++) {
            double newRes = 0.5*(res+a/res);
            if (abs(res - newRes) < 1e-9) {
                break;
            }
            res = newRes;
        }
        cout << res << endl;
        return res;
    }
};
int main() {
    Solution solve;
    ll x = 10000000000;
    ll res = solve.mySqrt(x);
    cout << res;
    return 0;
}