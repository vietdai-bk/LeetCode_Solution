#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> lettersMap;
        unordered_map<string, char> wordsMap;
        vector<string> s_list;
        string str="";
        for (int i=0;i<s.length();i++) {
            if (s[i]!=' ') {
                str+=s[i];
            } else {
                s_list.push_back(str);
                str="";
            }
        }
        s_list.push_back(str);
        if (pattern.length()!=s_list.size()) return false;
        for (int i=0;i<pattern.length();i++) {
            // cout << pattern[i] << " " << s_list[i] << endl;
            if (wordsMap.find(s_list[i])==wordsMap.end()) {
                wordsMap[s_list[i]] = pattern[i];
            } else {
                if (wordsMap[s_list[i]]!=pattern[i]) return false;
            }
            if (lettersMap.find(pattern[i])==lettersMap.end()) {
                lettersMap[pattern[i]] = s_list[i];
            } else {
                if (lettersMap[pattern[i]]!=s_list[i]) return false;
            }
        }
        return true;
    }
};

int main() {
    string pattern = "aaaa";
    string s = "dog cat cat dog";
    Solution solve;
    cout << solve.wordPattern(pattern, s);
}