#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        for (int i=0;i<prices.size()-1;i++) {
            prices[i] = prices[i+1] - prices[i];
            max_profit += prices[i] > 0 ? prices[i] : 0;
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solve;
    cout << solve.maxProfit(prices);
}