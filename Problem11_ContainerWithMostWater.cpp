#include <bits/stdc++.h>
using namespace std;
/*
* Ý tưởng:
* Bắt đầu với cột đầu tiên i=0, và cột cuối cùng j=height.size - 1
* cố định cột có height nhỏ hơn, giả sử là cột j, thể tích = h(j)*(j-i)
* bây giờ nếu ta duyệt i = 1 tới height.size - 2
* thể tích = min(h(i),h(j))*(j-i)
* rõ ràng j-i giảm vì giữ nguyên i và tăng j, còn min(h(i),h(j)) <= h(j)
* => giá trị thể tích luôn nhỏ hơn h(j)*(j-i) -> chỉ cần nhảy j = j - 1
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int capity = 0;
        int max = min(height[i],height[j])*(j-i);
        while (i<j) {
            if (height[i] < height[j]) {
                capity = height[i]*(j-i);
                i++;
            } else {
                capity = height[j]*(j-i);
                j--;
            }
            // cout << capity << endl;
            max = capity > max ? capity : max;
        }
        return max;
    }
};
int main() {
    Solution solve;
    vector<int> height = {1,1};
    cout << solve.maxArea(height);
}