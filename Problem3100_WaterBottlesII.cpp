#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles=numBottles, bottlesDrunk=numBottles;
        numBottles=0;
        while (!(emptyBottles<numExchange && numBottles==0)) {
            if (emptyBottles >= numExchange) {
                numBottles+=1;
                emptyBottles-=numExchange;
                numExchange+=1;
            }
            else {
                bottlesDrunk+=numBottles;
                emptyBottles=emptyBottles+numBottles;
                numBottles=0;
            }
        }
        return bottlesDrunk;
    }
};

int main() {
    Solution solve;
    const int numBottles=13, numExchange=6;
    cout << solve.maxBottlesDrunk(numBottles, numExchange);
}