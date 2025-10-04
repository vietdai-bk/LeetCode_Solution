#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest=i;
        int left=2*i+1, right=2*i+2;
        if (left<n && nums[left] > nums[largest]) {
            largest=left;
        }
        if (right<n && nums[right] > nums[largest]) {
            largest=right;
        }
        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=n/2-1;i>=0;i--) {
            heapify(nums, n, i);
        }
        // extractHeap
        for (int i=0;i<k-1;i++) {
            nums[0] = nums[nums.size()-1];
            nums.pop_back();
            heapify(nums, nums.size(), 0);
        }
        return nums[0];
    }
};

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    const int k=4;
    Solution solve;
    cout << solve.findKthLargest(nums, k);
}