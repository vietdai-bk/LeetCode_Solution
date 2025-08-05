#include <bits/stdc++.h>
using namespace std;
#define INTMAX 4294967295LL
#define INTMIN -4294967296LL
int64_t reverse(int64_t);
class Solution {
public:
    int64_t reverse(int64_t x) {
        int64_t num_reverse = 0;
        int64_t carry = 0;
        while (x!=0) {
            carry=x%10;
            x/=10; // 429496729
            if (num_reverse > INTMAX/10 || (num_reverse == INTMAX/10 && carry > 5)) {
                return 0;
            }
            if (num_reverse < INTMIN/10 || (num_reverse == INTMIN/10 && carry < -6)) {
                return 0;
            }
            num_reverse = num_reverse*10 + carry;
        }
        return num_reverse;
    }
};
int main() {
    cout << INTMAX << " " << INTMIN << endl;
    Solution solve;
    int64_t x = 6927694924; // 5927694924, -6927694924
    cout << x << endl;
    cout << solve.reverse(x);
}

// bonus tối ưu hơn nhưng phải dùng long
/*
class Solution {
 public:
  int reverse(int x) {
    long ans = 0;

    while (x != 0) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }

    return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
  }
};
*/