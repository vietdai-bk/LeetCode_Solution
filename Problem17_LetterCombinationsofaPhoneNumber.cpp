#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> letter = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        vector<string> res;
        if (isdigit(digits[0])) {
            for (char c : letter[digits[0]-'0']) {
                if (isdigit(digits[1])) {
                    for (char x : letter[digits[1]-'0']) {
                        if (isdigit(digits[2])) {
                            for (char k : letter[digits[2]-'0']) {
                                if (isdigit(digits[3])) {
                                    for (char m : letter[digits[3]-'0']) {
                                        string s = string(1,c) + x + k + m;
                                        res.push_back(s);
                                    }
                                } else {
                                    string s = string(1,c) + x + k;
                                    res.push_back(s);
                                }
                            }
                        } else {
                            string s = string(1,c) + x;
                            res.push_back(s);
                        }
                    }
                } else {
                    string s = string(1,c);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};
int main() {
    string digits = "2";
    Solution solve;
    vector<string> res = solve.letterCombinations(digits);
    for (int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
}
// backtracking
/*
class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
      map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"} 
      }; 

        string s = "";
      find(digits, 0, s, m);

      return ans; 
    }

    void find(string dig, int index, string &s, map<char,string> &m) {
        // cout<<s<<endl;
        if(index == dig.length() && s.size() > 0) {
            ans.push_back(s);
            return;
        }

        for(int i=0;i<m[dig[index]].size();i++) {
            s+=m[dig[index]][i];
            find(dig, index+1, s, m);
            s.pop_back();
        }
    }
};
*/