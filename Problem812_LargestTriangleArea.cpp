#include <bits/stdc++.h>
using namespace std;

// Area = |0.5*[(x1(y2-y3))+x3(y1-y2)+x2(y3-y1)]|
class Solution {
public:
    double triangleArea(vector<vector<int>>& points, int i, int j, int k) {
        return abs(
            0.5 * (
                points[i][0] * (points[j][1] - points[k][1]) +
                points[k][0] * (points[i][1] - points[j][1]) +
                points[j][0] * (points[k][1] - points[i][1])
            )
        );

    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea=0;
        int n=points.size();
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                for (int k=j+1;k<n;k++) {
                    double area = triangleArea(points, i, j, k);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solve;
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << solve.largestTriangleArea(points);
}