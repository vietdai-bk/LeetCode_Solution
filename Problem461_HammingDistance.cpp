#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xorxy = x^y;
        while (xorxy!=0) {
            if (xorxy&1) count+=1;
            xorxy=xorxy>>1;
        }
        return count;
    }
};

int main() {
    int x = 100, y = 200;
    Solution solve;
    cout << solve.hammingDistance(x, y);
}