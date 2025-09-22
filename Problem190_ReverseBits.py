class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        k = 31
        while n!=0:
            res += (n&1)*pow(2, k)
            k-=1
            n=n>>1
        return res

if __name__ == "__main__":
    solve = Solution()
    n = 2147483644
    print(solve.reverseBits(n))