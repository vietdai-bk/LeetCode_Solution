#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        for (int i=n-1;i>=0;i--) {
            if (digits[i] == 9) {
                carry = 1;
                digits[i] = 0;
            }
            else {
                carry = 0;
                digits[i] += 1;
                break;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution solve;
    vector<int> digits = {1, 9, 9, 9};
    vector<int> res  = solve.plusOne(digits);
    for (int digit : digits) {
        cout << digit << " ";
    }
    return 0;
}