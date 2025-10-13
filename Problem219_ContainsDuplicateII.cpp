#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i=0;i<nums.size();i++) {
            if (map.find(nums[i])==map.end()) {
                map[nums[i]] = i;
            } else {
                if (abs(i-map[nums[i]])<=k) return true;
                else map[nums[i]]=i;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,9};
    const int k = 3;
    Solution solve;
    cout << solve.containsNearbyDuplicate(nums, k);
}