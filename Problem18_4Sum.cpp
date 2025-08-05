#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = start; i < n - 2; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            long long complement = (long long)target - nums[i];
            if (complement > INT_MAX || complement < INT_MIN) {
                return {{}};
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < complement) {
                    l++;
                } else if (sum > complement) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int complement = target - nums[i];
            if (complement > INT_MAX || complement < INT_MIN) {
                return {{}};
            }
            for (auto &triplet : threeSum(nums, i + 1, complement)) {
                if (triplet.size() == 3) {
                    triplet.push_back(nums[i]);
                    sort(triplet.begin(),triplet.end());
                    res.push_back(triplet);
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
int main() {
    vector<vector<int>> res;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution solve;
    res = solve.fourSum(nums, target);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

//
/*
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    ranges::sort(nums);
    nSum(nums, 4, target, 0, nums.size() - 1, path, ans);
    return ans;
  }

 private:
  // Finds n numbers that add up to the target in [l, r].
  void nSum(const vector<int>& nums, long n, long target, int l, int r,
            vector<int>& path, vector<vector<int>>& ans) {
    if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
      return;
    if (n == 2) {
      // Similar to the sub procedure in 15. 3Sum
      while (l < r) {
        const int sum = nums[l] + nums[r];
        if (sum == target) {
          path.push_back(nums[l]);
          path.push_back(nums[r]);
          ans.push_back(path);
          path.pop_back();
          path.pop_back();
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        } else if (sum < target) {
          ++l;
        } else {
          --r;
        }
      }
      return;
    }

    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
      path.pop_back();
    }
  }
};
*/