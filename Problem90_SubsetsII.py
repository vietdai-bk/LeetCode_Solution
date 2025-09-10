from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res, subRes = [], []
        def backtrack(start):
            res.append(subRes.copy())
            for i in range(start, len(nums)):
                if i>start and nums[i]==nums[i-1]: continue
                subRes.append(nums[i])
                backtrack(i+1)
                subRes.pop()
        nums.sort()
        backtrack(0)
        return res

if __name__=="__main__":
    solve = Solution()
    print(solve.subsetsWithDup([1,2,2]))
    print(pow(2,16))