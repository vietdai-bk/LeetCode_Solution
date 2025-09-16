#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int start, string s) {
        int n=s.length();
        if (start==n) {
            res.push_back(temp);
            return;
        }
        for (int i=start;i<n;i++) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i-start+1));
                backtrack(i+1, s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return res;
    }
};

int main() {
    Solution solve;
    string s = "aaab";
    vector<vector<string>> res = solve.partition(s);
    for (auto& row : res) {
        for (string s : row) cout << s << " ";
        cout << endl;
    }
}