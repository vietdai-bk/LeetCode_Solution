#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size(), count=1;
        bool flag=true;
        if (k < 3) return k;
        for (int i=1;i<k;i++) {
            if (nums[i]==nums[i-1]) {
                count+=1;
            }
            if (nums[i] != nums[i-1] && count>2) {
                cout << count << endl;
                int m=i-(count-2);
                k-=count-2;
                for (int j=m;j<k;j++) {
                    cout << j+count-2 << endl;
                    nums[j] = nums[j+count-2];
                }
                count=1;
                i=m;
            }
            if (nums[i] != nums[i-1]) count=1;
        }
        if (count > 2) {
            k-=count-2;
            count=1;
        }
        for (int i=0;i<k;i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return k;
    }
};

int main() {
    vector<int> nums = {1,2,2,3,4,5,5,5,6,6,6,6,6};
    Solution solve;
    cout << solve.removeDuplicates(nums);
}