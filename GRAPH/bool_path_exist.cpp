#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};

    bool isSafe(int x, int y, int n, int m, vector<vector<int>> &grid)
    {
        // Check that indices are within bounds and the cell is not blocked (not 0)
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0);
    }

    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q)
    {
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty())
        {
            int firstnode = q.front().first;
            int secondnode = q.front().second;
            q.pop();

            // Check for all four possible directions
            for (int k = 0; k < 4; k++)
            {
                int new_i = firstnode + row[k];
                int new_j = secondnode + col[k];

                // Check if new position is within bounds and safe
                if (isSafe(new_i, new_j, grid.size(), grid[0].size(), grid))
                {
                    // If we reached the destination
                    if (grid[new_i][new_j] == 2)
                    {
                        return true;
                    }

                    // If the new position is not visited and is traversable (cell with 3)
                    if (!visited[new_i][new_j] && grid[new_i][new_j] == 3)
                    {
                        q.push({new_i, new_j});
                        visited[new_i][new_j] = true;
                    }
                }
            }
        }

        return false;
    }

    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // Loop through the grid to find the starting point (source cell with 1)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Call DFS from the source cell
                    if (dfs(i, j, grid, visited, q))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall (blocked cell which we cannot traverse).
// Note: There are only a single source and a single destination.