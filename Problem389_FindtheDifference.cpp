#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map1, map2;
        for (char c : s) {
            map1[c]+=1;
        }
        for (char c : t) {
            map2[c]+=1;
        }
        for (char c : t) {
            
            if (map1.find(c)==map1.end()) return c;
            else {
                if (map1[c]!=map2[c]) return c;
            }
        }
        return 'N';
    }
};

int main() {
    string s = "a", t = "aa";
    Solution solve;
    cout << solve.findTheDifference(s, t);
}