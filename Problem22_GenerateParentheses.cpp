#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backTrack(vector<string>& results, string current, int count_open, int count_close, int n) {
        if (current.length() == 2*n) { // thêm chuỗi vào kết quả khi đủ độ dài
            results.push_back(current);
            return;
        }
        if (count_open < n) { // nếu số dấu mở < n thì thêm "(" hoặc ")" để tiếp tục
            backTrack(results, current + "(", count_open+1, count_close,n);
        }
        if (count_close < count_open) { // tương tự trên
            backTrack(results, current + ")", count_open, count_close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        backTrack(results, "", 0, 0, n);
        return results;
    }
};
int main() {
    Solution solve;
    int n = 3;
    vector<string> results;
    results = solve.generateParenthesis(n);
    for (string s : results) {
        cout << s << " ";
    }
}