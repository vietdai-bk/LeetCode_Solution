#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size()<2) return;
        int l=0, r=s.size()-1;
        while (l<=r) {
            swap(s[l], s[r]);
            l+=1;
            r-=1;
        }
        for (int i=0;i<s.size();i++) cout << s[i] << " ";
    }
};

int main() {
    vector<char> s={'h','e','l','l','o'};
    Solution solve;
    solve.reverseString(s);
}