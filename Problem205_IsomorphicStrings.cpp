#include <bits/stdc++.h>
using namespace std;

// Note: đảm bảo sau ánh xạ không bị trùng đích.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_map<char, char> check;
        if (s.length()!=t.length()) return false;
        for (int i=0;i<s.length();i++) {
            if (check.find(t[i])!=check.end() && check[t[i]]!=s[i]) return false;
            else check[t[i]] = s[i];
            if (mapping.find(s[i])==mapping.end()) {
                mapping[s[i]] = t[i];
            }
            if (mapping[s[i]]!=t[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution solve;
    string s="paper", t="title";
    cout << solve.isIsomorphic(s, t);
}