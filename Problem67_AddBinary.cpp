#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        int carry = 0, i = n1-1, j = n2-1;
        string res = "";
        while(i>=0 || j>=0 || carry!=0) {
            int xa = 0, xb = 0;
            if (i >= 0) xa = int(a[i] - '0');
            if (j >= 0) xb = int(b[j] - '0');
            int sum = xa + xb + carry;
            carry = 0;
            if (sum == 2) {
                carry = 1;
                sum = 0;
            }
            else if (sum == 3) {
                carry = 1;
                sum = 1;
            }
            char lastbit = sum + '0';
            res = lastbit + res;
            i--;
            j--;
        }
        return res;
    }
};
int main() {
    Solution solve;
    string a = "1010", b = "1011";
    string res = solve.addBinary(a, b);
    cout << res;
    return 0;
}