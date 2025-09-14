#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return true;
            if (nums[mid]==nums[l]) {
                l+=1;
                continue;
            }
            if (nums[mid] >= nums[l]) {
                if (nums[mid] > target && target >= nums[l]) r = mid-1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[r]) l = mid+1;
                else r = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1};
    int target = 0;
    cout << solve.search(nums, target);
    return 0;
}