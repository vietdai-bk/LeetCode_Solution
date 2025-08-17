#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;
        int isFound = false;
        while (l <= r){
            mid = (l+r)/2;
            if (nums[mid] == target) {
                isFound = true;
                break;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (!isFound) return {-1, -1};
        l = mid;
        r = mid;
        while (l > 0 && nums[l-1] == target) l--;
        while (r < nums.size() -1 && nums[r+1] == target) r++;
        return {l, r};
    }
};
int main() {
    Solution solve;
    vector<int> nums = {5, 7, 7, 8, 8, 9, 10};
    int target = 8;
    vector<int> res = solve.searchRange(nums, target);
    for (int x : res) cout << x << " ";
    return 0;
}