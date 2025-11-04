#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> c={'u','e','o','a','i','U','E','O','A','I'};
        int l=0, r=s.length()-1;
        while (l<r) {
            while (l<r && find(c.begin(), c.end(), s[l])==c.end()) l+=1;
            while (l<r && find(c.begin(), c.end(), s[r])==c.end()) r-=1;
            if (l<r) swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main() {
    Solution solve;
    string s="IceCreAm";
    cout << solve.reverseVowels(s);
}