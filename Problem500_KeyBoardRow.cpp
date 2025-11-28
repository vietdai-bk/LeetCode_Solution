#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        unordered_map<char, int> map;
        vector<string> res;
        for (int i=0;i<s1.length();i++) {
            map[s1[i]]=1;
        }
        for (int i=0;i<s2.length();i++) {
            map[s2[i]]=2;
        }
        for (int i=0;i<s3.length();i++) {
            map[s3[i]]=3;
        }
        for (string s : words) {
            int j=map[tolower(s[0])];
            for (int i=1;i<s.length();i++) {
                if (map[tolower(s[i])]!=j) {
                    j=map[tolower(s[i])];
                    break;
                }
            }
            if (j==map[tolower(s[0])]) res.push_back(s);
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> res = solve.findWords(words);
    for (string s : res) cout << s << " ";
}