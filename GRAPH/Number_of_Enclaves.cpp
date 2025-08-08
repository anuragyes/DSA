// Number of Enclaves
#include <vector>
#include <queue>
using namespace std;

//  step 1: to solev mark all boundary one into  0 along with thier connected ones also becomes zero 
//  step 2: count the remaining ones in the grid


class Solution {
public:

    int count = 0;
    int n;
    int m;

    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    // Count remaining 1s in grid
    void solve(vector<vector<int>>& grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // Using BFS
        n = grid.size();
        m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isBoundary = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
                if (isBoundary && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; // mark as visited
                }
            }
        }

        while (!q.empty()) {
            int new_i = q.front().first;
            int new_j = q.front().second;
            q.pop();

            if (valid(new_i + 1, new_j) && grid[new_i + 1][new_j] == 1) {
                grid[new_i + 1][new_j] = 0;
                q.push({new_i + 1, new_j});
            }

            if (valid(new_i - 1, new_j) && grid[new_i - 1][new_j] == 1) {
                grid[new_i - 1][new_j] = 0;
                q.push({new_i - 1, new_j});
            }

            if (valid(new_i, new_j + 1) && grid[new_i][new_j + 1] == 1) {
                grid[new_i][new_j + 1] = 0;
                q.push({new_i, new_j + 1});
            }

            if (valid(new_i, new_j - 1) && grid[new_i][new_j - 1] == 1) {
                grid[new_i][new_j - 1] = 0;
                q.push({new_i, new_j - 1});
            }
        }

        solve(grid);
        return count;
    }
};

