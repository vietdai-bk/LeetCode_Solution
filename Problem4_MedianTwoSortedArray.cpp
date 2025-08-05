#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int half = (n1+n2)/2;
        if (n1==0) {
            return (n1+n2)%2==0 ? (double)(nums2[half]+nums2[half-1])/2 : nums2[half];
        } 
        if (n2==0) {
            return (n1+n2)%2==0 ? (double)(nums1[half]+nums1[half-1])/2 : nums1[half];
        }

        vector<int> nums;
        int i=0,j=0,k=0;
        while (i<n1 && j<n2 && k!=half+1) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
            k++;
        }
        // cout << i << " " << j << endl;
        while (i<n1 && k!=half+1) {
            nums.push_back(nums1[i]);
            i++;
        }
        while (j<n2 && k!=half+1) {
            nums.push_back(nums2[j]);
            j++;
        }
        double a = nums[half]+nums[half-1];
        double result = a/2;
        cout << fixed << setprecision(10) << result << endl;
        return (n1+n2)%2==0 ? (double)(nums[half]+nums[half-1])/2 : nums[half];
    }
};
int main() {
    vector<int> nums1 = {100001};
    vector<int> nums2 = {100000};
    Solution solve;
    double nums = solve.findMedianSortedArrays(nums1,nums2);
    cout << nums;
}