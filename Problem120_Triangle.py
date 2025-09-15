from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [[triangle[0][0]]]
        for i in range(1, len(triangle)):
            m = len(triangle[i])
            dp.append([0]*m)
            for j in range(m):
                if j==0: dp[i][j] = dp[i-1][j] + triangle[i][j]
                elif j==m-1: dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                else: dp[i][j] = min(dp[i-1][j]+triangle[i][j], dp[i-1][j-1]+triangle[i][j])
        print(dp)
        return min(dp[len(triangle)-1])

triangle = [[3],[3,3],[3,3,3],[3,3,3,3],[3,3,3,3,3],[3,3,3,3,3,3],[3,3,3,3,3,0,3]]
solve = Solution()
print(solve.minimumTotal(triangle))