from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            ans ^= x
        return ans
    
nums = [4,1,2,1,2]
solve = Solution()
print(solve.singleNumber(nums))