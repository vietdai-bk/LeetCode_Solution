#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int NUM_COL = 9, NUM_ROW = 9;
    const int SUB_BOARD = 3;
    bool checkRow(vector<vector<char>>& board, int k) {
        unordered_set<char> seen;
        for (int i=0;i<NUM_COL;i++) {
            if (seen.count(board[k][i]) && board[k][i] != '.') return false;
            seen.insert(board[k][i]);
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int k) {
        unordered_set<char> seen;
        for (int i=0;i<NUM_ROW;i++) {
            if (seen.count(board[i][k]) && board[i][k] != '.') return false;
            seen.insert(board[i][k]);
        }
        return true;
    }
    bool checkSubBoard(vector<vector<char>>& board, int row, int col) {
        unordered_set<char> seen;
        for (int i=row;i<SUB_BOARD+row;i++) {
            for (int j=col;j<SUB_BOARD+col;j++) {
                if (seen.count(board[i][j]) && board[i][j] != '.') return false;
                seen.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool validRow = true, validCol = true, validSub = true;
        for (int i=0;i<NUM_ROW;i++) {
            for (int j=0;j<NUM_COL;j++) {
                if (i%3==0 && j%3==0) validSub = checkSubBoard(board, i, j);
            }
            validRow = checkRow(board, i);
            validCol = checkCol(board, i);
        }
        if (validCol && validRow && validSub) return true;
        return false;
    }
};
int main() {
    Solution solve;
    vector<vector<char>> board = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    bool isValidS = solve.isValidSudoku(board);
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[i].size();j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    string res = isValidS ? "True" : "False";
    cout << res;
    return 0;
}