#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n=nums.size()/3;
        unordered_map<int, int> map;
        for (int x : nums) {
            map[x]+=1;
        }
        for (auto& p : map) {
            if (p.second > n) res.push_back(p.first);
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1,2};
    vector<int> res = solve.majorityElement(nums);
    for (int x : res) cout << x << " ";
}