#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]+=1;
        }
        for (int i=0;i<s.length();i++) {
            auto itr = map.find(s[i]);
            if (itr!=map.end() && itr->second==1) return i; 
        }
        return -1;
    }
};

int main() {
    string s = "aabb";
    Solution solve;
    cout << solve.firstUniqChar(s);
}