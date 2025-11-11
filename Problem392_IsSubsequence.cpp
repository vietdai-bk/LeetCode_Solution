#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1=0, l2=0;
        while (l1<s.length() && l2<t.length()) {
            if (s[l1]==t[l2]) {
                l1+=1;
                l2+=1;
            } else l2+=1;
            // cout << l1 << " " << l2 << endl;
        }
        if (l1==s.length() && l2<=t.length()) return true;
        return false; 
    }
};

int main() {
    string s = "abc", t = "ahbgdc";
    Solution solve;
    cout << solve.isSubsequence(s, t);
}