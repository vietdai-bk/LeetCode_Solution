from typing import List
import math

# (n, k) = C(n,k) = n!/k!(n-k)!

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = []
        for i in range(rowIndex+1):
            Cnk = math.factorial(rowIndex)//(math.factorial(i)*math.factorial(rowIndex-i))
            res.append(Cnk)
        return res

rowIndex = 4
solve = Solution()
print(solve.getRow(rowIndex))