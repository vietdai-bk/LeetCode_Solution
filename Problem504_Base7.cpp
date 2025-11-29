#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num<7) return num;
        string res;
        bool flag=false;
        if (num<0) flag=true;
        num = abs(num);
        while (num!=0) {
            res.push_back('0'+(num%7));
            num/=7;
        }
        if (flag) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    const int num = -7;
    Solution solve;
    cout << solve.convertToBase7(num);
}