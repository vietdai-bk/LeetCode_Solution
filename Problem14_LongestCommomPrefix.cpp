#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        bool isTrue = true;
        int j=0;
        while (isTrue && j<strs[0].length()) {
            char s = strs[0][j];
            for (int i=1;i<strs.size();i++) {
                char c = strs[i][j];
                if (s != c) {
                    isTrue = false;
                }
            }
            if (isTrue)
                lcp += s;
            j++;
        }
        return lcp;
    }
};
int main() {
    vector<string> strs = {"flower","","flight"};
    Solution solve;
    cout << solve.longestCommonPrefix(strs);
}