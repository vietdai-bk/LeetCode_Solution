#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> avoidFlood(vector<int>& rains) {
    //     unordered_map<int, int> full;
    //     set<int> dry_days;
    //     int n = rains.size();
    //     vector<int> res(n,-1);
    //     for (int i=0;i<n;i++) {
    //         if (rains[i]!=0) {
    //             cout << rains[i] << endl;
    //             if (full.find(rains[i])!=full.end() && *dry_days.begin() > i) return {};
    //             if (full.find(rains[i])!=full.end() && *dry_days.begin() < i) {
    //                 res[*dry_days.begin()] = rains[i];
    //                 dry_days.erase(dry_days.begin());
    //             }
    //             if (full.find(rains[i])==full.end()) full[rains[i]]=i;
    //         }
    //         else {
    //             dry_days.insert(i);
    //         }
    //     }
    //     return res;
    // }
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> full;
        set<int> dry_days;

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                res[i] = -1;
                if (full.count(lake)) {
                    auto it = dry_days.lower_bound(full[lake]);
                    if (it == dry_days.end()) {
                        return {};
                    }
                    res[*it] = lake;
                    dry_days.erase(it);
                }

                full[lake] = i;
            } 
            else {
                dry_days.insert(i);
            }
        }
        return res;
    }

};

int main() {
    vector<int> rains = {1,2,0,0,2,1};
    Solution solve;
    vector<int> res = solve.avoidFlood(rains);
    for (int x : res) {
        cout << x << " ";
    }
}