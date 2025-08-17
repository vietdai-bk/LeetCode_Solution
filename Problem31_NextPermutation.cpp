#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1, j = -1;
        for (int i=n-2;i>=0;i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k==-1) {
            for (int i=0;i<n/2;i++) {
                swap(nums[i], nums[n-i-1]);
            }
        }
        else {
            for (int i=n-1;i>=0;i--) {
                if (nums[i] > nums[k]) {
                    j = i;
                    break;
                }
            }
            cout << k << " " << j << endl;
            swap(nums[k], nums[j]);
            int l = k + 1, r = n - 1;
            while (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        for (int x : nums) cout << x << " ";
    }
};
// [3, 5, 4, 1] -> i = 0 -> 3, k=0,i=1,n-i=3
int main() {
    Solution solve;
    vector<int> nums = {4,2,0,2,3,2,0};
    solve.nextPermutation(nums);
    return 0;
}