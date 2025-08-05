#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        bool check_first_letter = false;
        for (int i=n-1;i>=0;i--) {
            if (s[i]!=' ' && !check_first_letter) {
                check_first_letter = true;
            }
            if (s[i]==' ' && check_first_letter) {
                break;
            }
            if (s[i]!=' ' && check_first_letter) {
                count++;
            }
        }
        return count;
    }
};
int main() {
    Solution solve;
    string s = "luffy is still joyboy";
    int res = solve.lengthOfLastWord(s);
    cout << res;
    return 0;
}