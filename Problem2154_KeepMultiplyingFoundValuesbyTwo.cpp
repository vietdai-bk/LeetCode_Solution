#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> nums_set(nums.begin(), nums.end());
        while (nums_set.count(original)==1) {
            original=original*2;
        }
        return original;
    }
};

int main() {
    vector<int> nums = {2,7,9};
    const int original = 4;
    Solution solve;
    cout << solve.findFinalValue(nums, original);
}