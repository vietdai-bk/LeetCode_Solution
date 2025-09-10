from typing import List

class Solution:
    def grayCode(self, n: int) -> List[int]:
        binCode = [] 
        subSet = []
        def backtrack(pos):
            if pos>=n:
                binCode.append(subSet.copy())
                return
            for c in ['0','1']:
                subSet.append(c)
                backtrack(pos+1)
                subSet.pop()
        backtrack(0)
        for i in range(len(binCode)):
            for j in range(n-1,0,-1):
                if binCode[i][j-1] == '1':
                    binCode[i][j] = '1' if binCode[i][j]=='0' else '0'
        num = ["".join(listNum) for listNum in binCode]
        res = [int(s, 2) for s in num]
        return res
    
if __name__ == "__main__":
    solve = Solution()
    print(solve.grayCode(2))