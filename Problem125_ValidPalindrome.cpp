#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (int i=0;i<s.length();i++) {
            if (isdigit(s[i]) || isalpha(s[i])) {
                temp += s[i];
            }
        }
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        int l=0, r=temp.length()-1;
        while (l <= r) {
            cout << temp[l] << " " << temp[r] << endl;
            if (temp[l] != temp[r]) return false;
            l+=1;
            r-=1;
        }
        return true;
    }
};

int main() {
    Solution solve;
    string s = "A man, a plan, a canal: Panama";
    bool isPalind = solve.isPalindrome(s);
    cout << isPalind;
}