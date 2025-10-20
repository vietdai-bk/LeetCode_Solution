#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0, n=nums.size();
        for (int x : nums) {
            sum+=x;
        }
        return n*(n+1)/2-sum;
    }
};

int main() {
    vector<int> nums = {0};
    Solution solve;
    cout << solve.missingNumber(nums);
}