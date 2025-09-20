#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n==0) intervals.push_back(newInterval);
        bool flag = true;
        if (newInterval[0]<=intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            flag = false;
            n+=1;
        }
        if (n>=2 && newInterval[0]>=intervals[0][0] && newInterval[0]<=intervals[1][0] && flag) {
            intervals.insert(intervals.begin()+1, newInterval);
            n+=1;
            flag = false;
        } else if (n==1 && flag) {
            if (newInterval[0]<=intervals[0][0]) {
                intervals.insert(intervals.begin(), newInterval);
            }
            else intervals.push_back(newInterval);
            flag = false;
            n+=1;
        }
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int m = res.size()-1;
        for (int i=1;i<n;i++) {
            if (i+1<n && newInterval[0]>=intervals[i][0] && intervals[i+1][0]>=newInterval[0] && flag) {
                intervals.insert(intervals.begin()+i+1,newInterval);
                n+=1;
                flag = false;
            } else if (i+1==n && flag) {
                intervals.push_back(newInterval);
                n+=1;
                flag = false;
            }
            int last = res[m][1];
            if (last >= intervals[i][0]) res[m][1] = last >= intervals[i][1] ? last : intervals[i][1];
            else res.push_back(intervals[i]);
            m = res.size()-1;
        }
        for (auto& row : intervals) {
            for (int x : row) cout << x << " ";
            cout << endl;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> nums = {{1,2}};
    vector<int> newInterval = {4,8};
    Solution solve;
    vector<vector<int>> res = solve.insert(nums, newInterval);
    cout << "RESULTS: " << endl;
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}