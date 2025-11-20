#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i<g.size() && j<s.size()) {
            if (g[i]<=s[j]) {
                count+=1;
                i+=1;
                j+=1;
            } else j+=1;
        }
        return count;
    }
};

int main() {
    vector<int> g = {1,2}, s = {1,2,3};
    Solution solve;
    cout << solve.findContentChildren(g, s);
}