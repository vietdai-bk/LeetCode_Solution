#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;
        int value=0;
        for (int i=0;i<s.length();i++) {
            if (symbol[s[i]] < symbol[s[i+1]]) {
                value -= symbol[s[i]];
            } else {
                value += symbol[s[i]];
            }
        }
        return value;
    }
};
int main() {
    Solution solve;
    string s = "VIXVI";
    cout << solve.romanToInt(s);
} 