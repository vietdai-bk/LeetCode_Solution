#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INTMAX 4294967295LL
#define INTMIN -4294967296LL
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        int j = 1;
        while (s[i]==' ') {
            i++;
        }
        cout << i << " ";
        if (s[i]=='-') {
            j = -1;
            i++;
        }
        else if (s[i]=='+') {
            i++;
        }
        cout << i << " ";
        ll nums = 0;
        while (isdigit(s[i]) && i < n) {
            int x = s[i] - '0';
            nums = nums*10 + x;
            if (j*nums > INTMAX) {
                return INTMAX;
            }
            if (j*nums < INTMIN) {
                return INTMIN;
            }
            i++; 
        }
        return j*nums;
    }
};
int main() {
    Solution solve;
    string s = "1337c0d3";
    cout << solve.myAtoi(s);
}