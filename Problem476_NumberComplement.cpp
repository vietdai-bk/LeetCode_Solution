#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res=0;
        int i=0;
        while (num!=0) {
            res+=(!(num&1))*pow(2,i);
            i+=1;
            num=num>>1;
        }
        return res;
    }
};

int main() {
    Solution solve;
    const int num = 5;
    cout << solve.findComplement(num);
}