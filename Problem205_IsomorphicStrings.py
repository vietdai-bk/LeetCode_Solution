class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping = {}
        check = {}
        if len(s)!=len(t): return False
        for c1, c2 in zip(s, t):
            if c2 in check.keys() and check[c2]!=c1: return False
            else: check[c2] = c1
            if c1 not in mapping.keys():
                mapping[c1] = c2
            if mapping[c1]!=c2: return False
        return True

if __name__ == "__main__":
    solve = Solution()
    s = "paper"
    t = "title"
    print(solve.isIsomorphic(s, t))