#include <bits/stdc++.h>
using namespace std;

// Ý tưởng chính: dùng DFS or BFS tìm từ các ô lân cận biển vào. Chưa hiểu lắm:)), độ phức tạp O(n*m)
class Solution {
public:
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(const vector<vector<int>>& h, vector<vector<bool>>& vis, int r, int c) {
        int m = h.size(), n = h[0].size();
        vis[r][c] = true;
        for (auto &d: dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                // đi ngược: chỉ sang ô có height >= current
                if (h[nr][nc] >= h[r][c]) {
                    dfs(h, vis, nr, nc);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty() || heights[0].empty()) return res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        // Pacific: top row and left col
        for (int j = 0; j < n; ++j) if (!pac[0][j]) dfs(heights, pac, 0, j);
        for (int i = 0; i < m; ++i) if (!pac[i][0]) dfs(heights, pac, i, 0);
        // Atlantic: bottom row and right col
        for (int j = 0; j < n; ++j) if (!atl[m-1][j]) dfs(heights, atl, m-1, j);
        for (int i = 0; i < m; ++i) if (!atl[i][n-1]) dfs(heights, atl, i, n-1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> nums = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    Solution solve;
    vector<vector<int>> res = solve.pacificAtlantic(nums);
    for (auto row : res) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}