#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int res = INT_MIN;
        for (int start = 0; start < k; ++start) {
            int sum = 0;
            for (int i = start; i < n; i += k)
                sum += energy[i];
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    vector<int> energy = {5, 2, -10, -5, 1};
    const int k = 3;
    Solution solve;
    cout << solve.maximumEnergy(energy, k);
}