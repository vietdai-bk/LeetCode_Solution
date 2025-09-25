#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfSquare(int n) {
        long long res=0;
        while (n>0) {
            int temp = n%10;
            n/=10;
            res += temp*temp;
        }
        return res;
    }
    bool isHappy(int n) {
        long long temp = sumOfSquare(n);
        if (temp==1) return true;
        unordered_map<int, int> check;
        while (temp != n) {
            cout << temp << " ";
            if (check[temp]) return false;
            check[temp]=1;
            if (temp==1) return true;
            temp = sumOfSquare(temp);
        }
        cout << endl;
        return false;
    }
};

int main() {
    const int n=4;
    Solution solve;
    bool isHap = solve.isHappy(n);
    cout << isHap << INT_MAX;
}