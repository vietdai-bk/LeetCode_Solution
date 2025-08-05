#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        int n = stones.size();
        if (n < 2) {
            return stones[0];
        }
        sort(stones.begin(), stones.end());
        int x = stones[n-2], y = stones[n-1];
        while (x != 0 && y != 0) {
            int sub = y - x;
            stones[n-2] = 0;
            stones[n-1] = sub;
            sort(stones.begin(), stones.end());
            x = stones[n-2], y = stones[n-1];
        }
        return *max_element(stones.begin(), stones.end());
    }
};

int main() {
    Solution solve;
    std::vector<int> v = {2,7,4,1,8,1};
    int res = solve.lastStoneWeight(v);
    std::cout << std::endl << res;
    return 0;
}