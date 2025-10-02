#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]+=1;
            if (count[x]==2) return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    Solution solve;
    bool isContain = solve.containsDuplicate(nums);
    cout << isContain;
}