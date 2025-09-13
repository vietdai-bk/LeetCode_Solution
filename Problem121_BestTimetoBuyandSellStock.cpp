#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        for (int i=0;i<n-1;i++) {
            prices[i]=prices[i+1]-prices[i];
        }
        int sum=0, max_profit=0;
        for (int i=0;i<n-1;i++) {
            sum = max(prices[i], sum+prices[i]);
            max_profit = max(sum, max_profit);
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solve;
    cout << solve.maxProfit(prices);
}