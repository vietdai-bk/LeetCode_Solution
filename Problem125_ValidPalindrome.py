class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s)-1
        while l<=r:
            if not s[l].isdigit() and not s[l].isalpha():
                l+=1
                continue
            if not s[r].isdigit() and not s[r].isalpha():
                r-=1
                continue
            c1 = s[l].lower()
            c2 = s[r].lower()
            print(c1, c2)
            if c1 != c2: return False
            l+=1
            r-=1
        return True

s = "0P"
solve = Solution()
print(solve.isPalindrome(s))