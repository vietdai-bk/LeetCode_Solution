#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int partition(vector<vector<int>>& nums, int l, int r) {
        int pivot = nums[r][2];
        int j=l-1;
        for (int i=l;i<r;i++) {
            if (nums[i][2]<pivot) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[j+1], nums[r]);
        return j+1;
    }

    void quickSort(vector<vector<int>>& nums, int l, int r) {
        if (l<r) {
            int mid = partition(nums, l, r);
            quickSort(nums, l, mid-1);
            quickSort(nums, mid+1, r);
        }
    }

    bool isConnected(vector<vector<bool>>& grid, vector<int> start, vector<int> end) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        int sr = start[0], sc = start[1];
        int er = end[0], ec = end[1];

        if (!grid[sr][sc] || !grid[er][ec]) return false;

        q.push({sr, sc});
        visited[sr][sc] = true;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            auto front = q.front();
            int r = front.first;
            int c = front.second;

            q.pop();

            if (r == er && c == ec)
                return true;

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int maxHeight=0;
        int n = grid.size();
        vector<vector<int>> listGrid;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[i].size();j++) {
                listGrid.push_back({i, j, grid[i][j]});
                maxHeight = max(maxHeight, grid[i][j]);
            }
        }
        cout << maxHeight << endl;
        quickSort(listGrid, 0, listGrid.size()-1);
        vector<vector<bool>> isConnect(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i=0;i<listGrid.size();i++) {
            isConnect[listGrid[i][0]][listGrid[i][1]]=true;
            if (isConnected(isConnect, {0, 0}, {n-1, n-1})) return listGrid[i][2];
        }
        for (auto& p : listGrid) {
            for (int x : p) cout << x << " ";
            cout << endl;
        }
        return maxHeight;
    }
};

int main() {
    vector<vector<int>> grid = {{0,2},{1,3}};
    Solution solve;
    cout << solve.swimInWater(grid);
}