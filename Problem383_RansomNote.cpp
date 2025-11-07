#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransom;
        unordered_map<char, int> maga;
        for (char c : ransomNote) ransom[c]+=1;
        for (char c : magazine) maga[c]+=1;
        for (auto& p : ransom) {
            if (maga[p.first]<p.second) return false; 
        }
        return true;
    }
};

int main() {
    string ransomNote = "aa", magazine = "aba";
    Solution solve;
    cout << solve.canConstruct(ransomNote, magazine);
}