#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sorting(vector<vector<int>>& nums, int l, int r) {
        int pivot = nums[(l+r)/2][0];
        int i = l, j = r;
        while (i <= j) {
            while (nums[i][0] < pivot) i++;
            while (nums[j][0] > pivot) j--;
            if (i <= j) {
                vector<int> temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        if (i < r) sorting(nums, i, r);
        if (l < j) sorting(nums, l, j);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sorting(intervals, 0, intervals.size()-1);
        res.push_back(intervals[0]);
        int n = res.size()-1;
        for (int i=1;i<intervals.size();i++) {
            int last = res[n][1];
            if (intervals[i][0] <= last) {
                res[n][1] = last >= intervals[i][1] ? last : intervals[i][1];
            }
            else res.push_back(intervals[i]);
            n = res.size()-1;
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<vector<int>> intervals = {{1,4}, {0,1}};
    vector<vector<int>> res = solve.merge(intervals);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}