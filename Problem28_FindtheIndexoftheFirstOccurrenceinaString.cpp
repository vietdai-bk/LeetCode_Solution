#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                j++;
                if(j == needle.size()) return i - j + 1; // khi j đến cuối chuỗi
            } else {
                i = i - j;
                j = 0;
            }
            i++;
        }
        return -1;
    }
};
int main() {
    Solution sol;
    string haystack = "hello", needle = "ll";
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}