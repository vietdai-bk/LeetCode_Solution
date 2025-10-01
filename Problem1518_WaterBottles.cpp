#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int canDrink=numBottles, drinked=0, empty=0;
        while ((empty+canDrink)>=numExchange) {
            drinked += canDrink;
            empty += canDrink;
            canDrink = empty / numExchange;
            empty = empty - canDrink*numExchange;
        }
        return drinked+canDrink;
    }
};

int main() {
    const int numBottles=15, numExchange=4;
    Solution solve;
    cout << solve.numWaterBottles(numBottles, numExchange);
}