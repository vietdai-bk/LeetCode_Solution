from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l=0
        sum=0
        res=len(nums)+1
        for i in range(len(nums)):
            sum+=nums[i]
            while sum>=target:
                res = min(i-l+1, res)
                sum-=nums[l]
                l+=1
        return res if res!=len(nums)+1 else 0
    
if __name__ == "__main__":
    solve = Solution()
    target = 213
    nums = [12,28,83,4,25,26,25,2,25,25,25,12]
    print(solve.minSubArrayLen(target, nums))