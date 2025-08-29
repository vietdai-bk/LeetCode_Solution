#include <bits/stdc++.h>
using namespace std;

// Các chuỗi bit có độ dài n
string curString;
void genString(int pos, int n);

// Dãy con tăng dần có độ dài k không đổi trong dãy từ 1...n
vector<int> curSubsequence;
void genSubsequence(int pos, int n, int k, int cur);

// Hoán vị của một mảng
vector<int> permutation;
void genPermutation(int pos, vector<int>& nums);

// Tập con không lặp
vector<vector<int>> subArr;
vector<int> oneSubArr;
void genSubArr(int start, vector<int> nums);

// Hàm main
int main() {
    const int n = 9, k = 4;
    vector<int> nums = {1, 2, 3};
    // genString(0, n);
    // genSubsequence(0, n, k, 1);
    // genPermutation(0, nums);
    genSubArr(0, nums);
    for (auto &row : subArr) {
        for (int x : row) cout << x << " "; 
        cout << endl;
    }
}

void genString(int pos, int n) {
    if (pos >= n) {
        cout << curString << endl;
        return;
    }
    for (char i='0';i<='1';i++) {
        curString.push_back(i);
        genString(pos+1, n);
        curString.pop_back();
    }
}

void genSubsequence(int pos, int n, int k, int cur) {
    if (pos >= k) {
        for (int x : curSubsequence) cout << x << " ";
        cout << endl;
        return;
    }
    for (int i=cur;i<=n;i++) {
        curSubsequence.push_back(i);
        genSubsequence(pos+1, n, k, i+1);
        curSubsequence.pop_back();
    }
}

void genPermutation(int pos, vector<int>& nums) {
    int n = nums.size();
    if (pos >= n) {
        for (int x : permutation) cout << x << " ";
        cout << endl;
        return;
    }
    for (int i=0;i<n;i++) {
        if (find(permutation.begin(), permutation.end(), nums[i]) == permutation.end()) {
            permutation.push_back(nums[i]);
            genPermutation(pos+1, nums);
            permutation.pop_back();
        }
    }
}

void genSubArr(int start, vector<int> nums) {
    subArr.push_back(oneSubArr);
    for (int i=start;i<nums.size();i++) {
        oneSubArr.push_back(nums[i]);
        genSubArr(i+1, nums);
        oneSubArr.pop_back();
    }
}