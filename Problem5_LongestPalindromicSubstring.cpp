#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n<2) {
            return s;
        }
        string results = "";
        for (int i=0;i<n-1;i++) {
            string str = "";
            int l = i;
            str += s[i];
            while (s[i] == s[i+1]) {
                i++;
                str += s[i];
            }
            int r = i;
            // cout << str << endl;
            // cout << l <<" "<<r<<endl;
            while (l-1>=0 && r+1<n && s[l-1] == s[r+1]) {
                str = s[l-1] + str + s[r+1];
                l--;
                r++;
            }
            // cout << str;
            // cout << results;
            if (results.length() < str.length()) {
                results = str;
            }
        }
        return results;
    }
};
int main() {
    string s = "babad";
    Solution solve;
    string str = solve.longestPalindrome(s);
    cout << str;
}