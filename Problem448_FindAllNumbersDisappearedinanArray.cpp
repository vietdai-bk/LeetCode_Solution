#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            map[nums[i]]+=1;
        }
        for (int i=1;i<=nums.size();i++) {
            if (map.find(i)==map.end()) res.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution solve;
    vector<int> res = solve.findDisappearedNumbers(nums);
    for (int x : res) cout << x << " ";
}