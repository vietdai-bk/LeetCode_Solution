from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n<2: return nums[0]
        if n<3: return nums[0] if nums[0]>nums[1] else nums[1]
        dp = [0]*n
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = nums[0]+nums[2]
        for i in range(3, n):
            dp[i] = max(nums[i]+dp[i-2], nums[i]+dp[i-3])
        return dp[n-1] if dp[n-1] > dp[n-2] else dp[n-2]

if __name__ == "__main__":
    solve = Solution()
    nums = [0,391,391,7,4,391,400,2,1,392,390,7,8,393,397,1,9,396,392,4,8,396,390,6,8,397,393,8,10,399,398,5,9,393,394,2,2,399,395,0,2,398,390,1,8,400,400,7,0,396,400,3,8,395,392,5,0,395,390,2,0,392,398,9,10,395,400,3,9,392,390,0,1,392,392,4,7,393,400,8,3,395,395,6,3,400,393,3,9,391,400,9,8,394,398,2,10,399,393,8]
    print(solve.rob(nums))