#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> symbol;
        symbol[1] = "I";
        symbol[4] = "IV";
        symbol[5] = "V";
        symbol[9] = "IX";
        symbol[10] = "X";
        symbol[40] = "XL";
        symbol[50] = "L";
        symbol[90] = "XC";
        symbol[100] = "C";
        symbol[400] = "CD";
        symbol[500] = "D";
        symbol[900] = "CM";
        symbol[1000] = "M";
        string roman = "";
        int key[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i = 0;
        while (num>0) {
            if (num >= key[i]) {
                num -= key[i];
                roman += symbol[key[i]];
            }
            else {
                i++;
            }
        }
        return roman;
    }
};
int main() {
    Solution solve;
    int num = 1999;
    cout << solve.intToRoman(num);
}