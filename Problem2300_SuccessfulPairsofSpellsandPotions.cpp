#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int k, long long success) {
        int l=0, r=nums.size();
        int mid = l+(r-l)/2;
        while (l<r) {
            mid = l+(r-l)/2;
            if (1LL*nums[mid]*k < success) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return spells[i] < spells[j];
        });
        sort(potions.begin(), potions.end());
        vector<int> res(n, 0);
        for (int k = 0; k < n; k++) {
            int i = idx[k];
            int temp = search(potions, spells[i], success);
            res[i] = m - temp;
        }

        return res;
        }
};

int main() {
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    long long success = 16;
    Solution solve;
    vector<int> res = solve.successfulPairs(spells, potions, success);
    for (int x : res) cout << x << " ";
}