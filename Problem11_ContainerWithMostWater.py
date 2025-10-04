from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        i=0
        j=len(height)-1
        maxA = 0
        while i<j:
            if height[i] < height[j]:
                area = height[i]*(j-i)
                i+=1
            else:
                area = height[j]*(j-i)
                j-=1
            maxA = maxA if maxA>area else area
        return maxA

if __name__ == "__main__":
    solve = Solution()
    height = [1,1]
    print(solve.maxArea(height))
        

# //i=0, j=n-1
# // nếu h(i) < h(j):(True)
# // h(i)*(j-i) = 1*(8-0) = 8
# // tăng i lên
# // else:
# // h(j)*(j-i) = 7*(8-1) = 49
# // giảm j xuống