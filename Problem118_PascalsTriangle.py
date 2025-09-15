from typing import List
import math
## Cong thuc tinh phan tu (n,k) = C(n,k) = n!/k!(n-k)! 

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(numRows):
            subRes = []
            for j in range(i+1):
                Cnk = (math.factorial(i))//(math.factorial(j)*math.factorial(i-j))
                subRes.append(Cnk)
            res.append(subRes)
        return res
    
numRows = 10
solve = Solution()
print(solve.generate(numRows))