#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int indexRepeat = -1;
        if (n==0) { // kiểm tra điều kiện nếu chuỗi rỗng.
            return 0;
        }
        int results[n];
        fill(results,results+n,1);
        for (int i=1;i<n;i++) {
            for (int j=i-1;j>=0;j--) {
                if (j == indexRepeat) {
                    break;
                }
                if (s[i] != s[j]) {
                    results[i]++;
                }
                if (s[i] == s[j]) {
                    indexRepeat = j;
                    break;
                }
            }
        }
        // for (int x : results) {
        //     cout << x << " ";
        // }
        // cout << endl;
        return *max_element(results, results + n);
    } 
};
int main() {
    Solution solve;
    string s = "bbbbb";
    cout << solve.lengthOfLongestSubstring(s);
}