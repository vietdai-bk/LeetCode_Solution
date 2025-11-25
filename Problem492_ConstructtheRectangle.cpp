#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i = sqrt(area);i>=1;i--) {
            if (area%i==0) {
                if (i > area/i) return {i, area/i};
                else return {area/i, i};
            }
        }
        return {area, 1};
    }
};

int main() {
    Solution solve;
    const int area = 37;
    vector<int> res = solve.constructRectangle(area);
    for (int x : res) cout << x << " ";
} 