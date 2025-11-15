#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int l=0, count=0;
        while (s[l]==' ') {
            l+=1;
        }
        for (int i=l;i<s.length();i++) {
            if (s[i]==' ') {
                count+=1;
                while (s[i]==' ') i+=1;
                i-=1;
            }
        }
        if (s[s.length()-1]!=' ') count+=1;
        return count;
    }
};

int main() {
    string s = " ";
    Solution solve;
    cout << solve.countSegments(s);
}