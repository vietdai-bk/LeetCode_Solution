#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUpper(char c) {
        if ((c>='A') && (c<='Z')) return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        if (word.length()==1) return true;
        if (!isUpper(word[0])) {
            for (int i=1;i<word.length();i++) {
                if (isUpper(word[i])) return false;
            }
            return true;
        }
        if (isUpper(word[0]) && isUpper(word[1])) {
            for (int i=2;i<word.length();i++) {
                if (!isUpper(word[i])) return false;
            }
            return true;
        }
        if (isUpper(word[0]) && !isUpper(word[1])) {
            for (int i=2;i<word.length();i++) {
                if (isUpper(word[i])) return false;
            }
            return true;
        }
        return false;
    }
};

int main() {
    string word = "FLaG";
    Solution solve;
    cout << solve.detectCapitalUse(word);
}