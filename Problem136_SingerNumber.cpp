#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int, int> count;
    //     for (int x : nums) {
    //         count[x]+=1;
    //         if (count[x]==2) {
    //             nums.erase(remove(nums.begin(), nums.end(), x), nums.end());
    //         }
    //     }
    //     return nums[0];
    // }
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x; // a^0 = a, a^a = 0
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,1,2,3,4,5,4,5,3,-1,2};
    Solution solve;
    cout << solve.singleNumber(nums);
}