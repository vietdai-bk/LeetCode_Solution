#include <bits/stdc++.h>
using namespace std;

class Solution { // Chạy đúng nhưng độ phức tạp O(n*(k%n)) => khá cao, bị time exceed
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for (int i=1;i<=k;i++) {
            int temp = nums[n-1];
            for (int j=n-1;j>=1;j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
        for (int x : nums) cout << x << " ";
    }
    void rotate_On(vector<int>& nums, int k) { // Đảo ngược mảng => O(n)
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        for (int x : nums) cout << x << " ";
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    const int k = 4;
    Solution solve;
    solve.rotate_On(nums, k);
}