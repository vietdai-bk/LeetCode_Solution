from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit=0
        for i in range(len(prices)-1):
            prices[i] = prices[i+1]-prices[i]
            max_profit += prices[i] if prices[i] > 0 else 0
        return max_profit
    
prices = [1,2,3,4,5]
solve = Solution()
print(solve.maxProfit(prices))