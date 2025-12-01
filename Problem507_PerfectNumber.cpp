#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 6) return false;
        int sum=1;
        for (int i=2;i*i<=num;i++) {
            if (num%i==0) {
                // cout << i << " ";
                if (i*i!=num) {
                    sum += i + num/i;
                }
                else sum += i;
            }
        }
        // cout << sum;
        if (num==sum) return true;
        return false;
    }
};

int main() {
    const int num = 7;
    Solution solve;
    cout << solve.checkPerfectNumber(num);
}