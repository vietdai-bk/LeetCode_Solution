#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> countNumber(string s) {
        vector<vector<int>> res;
        int count = 1;
        for (int i=0;i<s.length();i++) {
            if (s[i] == s[i+1]) {
                count += 1;
            }
            else if (i < s.length() - 1) {
                res.push_back({count, s[i] - '0'});
                count = 1;
            }
            else {
                res.push_back({count, s[i] - '0'});
                count = 1;
            }
        }
        return res;
    }
    string sayNumber(vector<vector<int>> v) {
        string res = "";
        for (int i=0;i<v.size();i++) {
            for (int j=0;j<v[i].size();j++) {
                res += v[i][j] + '0';
            }
        }
        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        for (int i=1;i<n;i++) {
            vector<vector<int>> pairNumber = countNumber(res);
            res = sayNumber(pairNumber);
        }
        return res;
    }
};
int main() {
    Solution solve;
    int n = 10;
    for (int i=1;i<=n;i++)
        cout << solve.countAndSay(i) << endl;
    return 0;
}