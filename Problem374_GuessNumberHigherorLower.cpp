#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int guess(int num, int pick) {
        if (pick<num) return -1;
        if (pick>num) return 1;
        return 0;
    }
    int guessNumber(int n) {
        long long l=1, r=n;
        if (!guess(n, 10)) return n;
        while (l<=r) {
            long long mid = (r+l)/2;
            int isGuess = guess(mid, 10);
            cout << mid << " " << isGuess << endl;
            if (isGuess==1) l=mid;
            if (isGuess==-1) r=mid;
            if (isGuess==0) return mid;
        }
        return 0;
    }
};

int main() {
    Solution solve;
    const int n=10;
    cout << solve.guessNumber(n);
}