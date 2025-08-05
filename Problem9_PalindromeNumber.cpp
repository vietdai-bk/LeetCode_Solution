#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.length();
        cout << s << " " << len << endl;
        if (x < 0) {
            return false;
        }
        int l=0, r=len-1;
        while (l<r) {
            if (s[l]==s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solve;
    int x = 1111;
    cout << solve.isPalindrome(x);
}
// bonus dùng cách như ở problem 7 và so sánh với giá trị x để kết luận sẽ nhanh hơn