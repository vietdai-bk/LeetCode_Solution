#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> combinations;
    string oneComb;
    int bin2Dec(string s) {
        int res=0, n=s.length();
        for (int i=0;i<n;i++) {
            res += (s[i]-'0')*pow(2,n-i-1);
        }
        return res;
    }
    void backtrack(int pos, int n) {
        if (pos>=n) {
            combinations.push_back(oneComb);
            return;
        }
        for (char i='0';i<='1';i++) {
            oneComb.push_back(i);
            backtrack(pos+1, n);
            oneComb.pop_back();
        }
    };
    vector<int> grayCode(int n) {
        backtrack(0, n);
        for (string s : combinations) cout << s << " ";
        cout << endl;
        for (int j=0;j<combinations.size();j++) {
            for (int i=n-1;i>=1;i--) {
                if (combinations[j][i-1]=='1') {
                    combinations[j][i] = (combinations[j][i]=='0') ? '1' : '0';
                }
            }
        }
        vector<int> res;
        for (string s : combinations) {
            res.push_back(bin2Dec(s));
        }
        return res;
    }
};

int main() {
    const int n=4;
    Solution solve;
    vector<int> res = solve.grayCode(n);
    for (int x : res) cout << x << " ";
}