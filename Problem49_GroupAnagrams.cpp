#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> temp = strs;
        unordered_map<string, vector<int>> groups;
        for (int i=0;i<temp.size();i++) {
            sort(temp[i].begin(), temp[i].end());
        }
        for (int i=0;i<temp.size();i++) {
            groups[temp[i]].push_back(i);
        }
        for (auto& p : groups) {
            cout << p.first << ": ";
            vector<string> oneRes;
            for (int idx : p.second) {
                cout << idx << " ";
                oneRes.push_back(strs[idx]);
            }
            res.push_back(oneRes);
            cout << endl;
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = solve.groupAnagrams(strs);
    for (auto& row : res) {
        for (string s : row) cout << s << " ";
        cout << endl;
    }
}