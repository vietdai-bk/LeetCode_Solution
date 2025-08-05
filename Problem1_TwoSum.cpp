#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;
        for (int i=0;i<nums.size();i++) {
            int complement = target - nums[i];
            if (numIndex.find(complement) != numIndex.end()) {
                return {numIndex[complement],i};
            }
            numIndex[nums[i]] = i;
        }
        return {};
    }
};
int main() {
    vector<int> nums = {3,3};
    int target = 6;
    Solution solve;
    vector<int> results = solve.twoSum(nums, target);
    for (int x : results) {
        cout << x << " ";
    }
}