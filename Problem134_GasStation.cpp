#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // đúng nhưng O(n^2) => time exceed
        int n = gas.size();
        for (int i=0;i<n;i++) {
            int start_index = i;
            int current_index = start_index;
            int fill = gas[start_index];
            while (true) {
                if (fill >= cost[current_index]) {
                    fill -= cost[current_index];
                    current_index = current_index+1<n ? current_index+1 : 0;
                    fill += gas[current_index];
                }
                else break;
                if (current_index == start_index) return start_index;
            }
        }
        return -1;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // tối ưu hơn: O(n)
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};

int main() {
    Solution solve;
    vector<int> gas = {2,0,0}, cost = {0,1,0};
    int res = solve.canCompleteCircuit(gas, cost);
    cout << res;
}