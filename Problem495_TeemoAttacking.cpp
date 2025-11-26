#include <bits/stdc++.h>
using namespace std;

/*
2 3 4
3 4 5
x1 - y1
x2 - y2
length = 2*duration - (y1-x2+1)
length = 2*3 - (4-3+1) = 4
2 3 4
4 5 6
length = 2*3 - (4-4+1) = 5 
1 2
2 3
length = 2*2-()
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int prevSecond = INT_MIN;
        for (int i=0;i<timeSeries.size();i++) {
            if (timeSeries[i]>prevSecond) res+=duration;
            else res+=2*duration - (prevSecond-timeSeries[i]+1) - duration;
            prevSecond = timeSeries[i]+duration-1; 
        }
        return res;
    }
};

int main() {
    vector<int> timeSeries = {1,2,3,4};
    const int duration = 2;
    Solution solve;
    cout << solve.findPoisonedDuration(timeSeries, duration);
}