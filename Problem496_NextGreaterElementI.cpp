#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i=0;i<nums1.size();i++) {
            int k=0;
            while (k<nums2.size()) {
                if (nums1[i]==nums2[k]) break;
                k+=1;
            }
            int j=k+1;
            while (j<nums2.size()) {
                if (nums1[i]<nums2[j]) break;
                j+=1;
            }
            if (j<nums2.size()) res.push_back(nums2[j]);
            else res.push_back(-1);
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    Solution solve;
    vector<int> res = solve.nextGreaterElement(nums1, nums2);
    for (int x : res) cout << x << " ";
}