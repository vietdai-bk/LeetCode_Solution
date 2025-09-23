from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k%len(nums)
        nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]

if __name__ == "__main__":
    nums = [1]
    k = 0
    solve = Solution()
    solve.rotate(nums, k)
    print(nums)