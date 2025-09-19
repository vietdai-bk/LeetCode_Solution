#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};

int main() {
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution solve;
    cout << solve.singleNumber(nums);
}