#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while (i < m + n && j < n) {
            int a = (i < m + n) ? nums1[i] : 0;
            int b = (j < n) ? nums2[j] : 0;
            cout << a << " " << b << endl;
            if (a > b) {
                nums1.insert(nums1.begin() + i, b);
                nums1.pop_back();
                j++;
                i++;
            }
            else i++;
        }
        while (j < n) {
            nums1[j+m] = nums2[j];
            j++;
        }
        for (int x : nums1) cout << x << " ";
    }
};
int main() {
    Solution solve;
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    int m = 3, n = 3;
    solve.merge(nums1, m, nums2, n);
    return 0;
}