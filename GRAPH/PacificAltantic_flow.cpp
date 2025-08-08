#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        queue<pair<int, int>> q;

        // Pacific (top row and left column)
        for (int j = 0; j < m; ++j) {
            pacific[0][j] = true;
            q.push({0, j});
        }
        for (int i = 0; i < n; ++i) {
            pacific[i][0] = true;
            q.push({i, 0});
        }

        // BFS for Pacific
        bfs(heights, pacific, q, n, m);

        // Atlantic (bottom row and right column)
        for (int j = 0; j < m; ++j) {
            atlantic[n - 1][j] = true;
            q.push({n - 1, j});
        }
        for (int i = 0; i < n; ++i) {
            atlantic[i][m - 1] = true;
            q.push({i, m - 1});
        }

        // BFS for Atlantic
        bfs(heights, atlantic, q, n, m);

        // Collect results
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int n, int m) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Up
            if (valid(x - 1, y, n, m) && !visited[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            }

            // Down
            if (valid(x + 1, y, n, m) && !visited[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }

            // Left
            if (valid(x, y - 1, n, m) && !visited[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            }

            // Right
            if (valid(x, y + 1, n, m) && !visited[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
        }
    }
};
