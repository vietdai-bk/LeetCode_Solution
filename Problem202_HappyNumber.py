class Solution:
    def sumOfSquares(self, n):
        res = 0
        while n!=0:
            res+=pow(n%10, 2)
            n//=10
        return res
    def isHappy(self, n: int) -> bool:
        temp = self.sumOfSquares(n)
        if temp==1: return True
        check = {}
        while temp!=n:
            print(temp)
            if temp not in check.keys(): check[temp]=0
            if check[temp]: return False
            if temp==1: return True
            check[temp]=1
            temp = self.sumOfSquares(temp) 
        return False

if __name__ == "__main__":
    solve = Solution()
    n = 2147483647
    print(solve.isHappy(n))