#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") return "0";
        int n1 = num1.length(), n2 = num2.length();
        int res[n1+n2] = {0};
        for (int i=n2-1;i>=0;i--) {
            for (int j=n1-1;j>=0;j--) {
                int mul = (num2[i] - '0') * (num1[j] - '0');
                int sum = mul + res[i+j+1];
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string res_str = "";
        for (int i=0;i<n1+n2;i++) {
            if ( i==0 && res[i] == 0) continue;
            char c = res[i] + '0';
            res_str += c;
        }
        return res_str;
    }
};
int main() {
    Solution solve;
    string num1 = "123", num2 = "456";
    cout << solve.multiply(num1, num2);
    return 0;
}