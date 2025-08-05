#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length() < 2) return false;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[') {
                st.push(s[i]);
            } else if (!st.empty()) {
                if (s[i] == ')' and st.top() == '(') st.pop();
                else if (s[i] == '}' and st.top() == '{') st.pop();
                else if (s[i] == ']' and st.top() == '[') st.pop();
                else return false;
            } else {
                return false;
            }
        } 
        if (st.empty()) return true;
        return false;
    }
};
int main() {
    Solution solve;
    string s = "){";
    bool check = solve.isValid(s);
    if (check) {
        cout << "True";
    } else {
        cout << "False";
    }
}