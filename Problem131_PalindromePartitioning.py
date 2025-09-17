from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        oneRes = []
        n = len(s)
        def isPalindrome(s, l, r):
                while l<=r:
                    if s[l]!=s[r]: return False
                    l+=1
                    r-=1
                return True
        def backtrack(start, s):
            if start == n:
                res.append(oneRes.copy())
                return
            for i in range(start, n):
                if isPalindrome(s, start, i):
                    oneRes.append(s[start:i+1])
                    backtrack(i+1, s)
                    oneRes.pop()
        backtrack(0, s)
        return res

solve = Solution()
s = "aab"
print(solve.partition(s))