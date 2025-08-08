#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//  Detect cycle in a 2D matrix using DFS or BFS

//   using dfs 

class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int parent_x, int parent_y, char ch) {
        visited[x][y] = true;

        // 4 directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (valid(nx, ny, grid.size(), grid[0].size()) && grid[nx][ny] == ch) {
                if (!visited[nx][ny]) {
                    if (dfs(grid, visited, nx, ny, x, y, ch)) {
                        return true;
                    }
                }
                else if (nx != parent_x || ny != parent_y) {
                    // Found a visited neighbor that's not parent — cycle detected
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};



//   using bfs 
class Solution
{
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m, int i, int j, int parent_i, int parent_j, char ch)
    {
        visited[i][j] = true;
        queue<pair<pair<int, int>, pair<int, int>>> q; //  store value indexes and parent indexes
        q.push({{i, j}, {parent_i, parent_j}});

        while (!q.empty())
        {
            int new_i = q.front().first.first;
            int new_j = q.front().first.second;
            int parent_i = q.front().second.first;
            int parent_j = q.front().second.second;
            q.pop();
            

             if(valid(new_i+1, new_j, n, m) && grid[new_i+1][new_j] == ch){
                if (!visited[new_i + 1][new_j])
                {
                    visited[new_i + 1][new_j] = true;
                    q.push({{new_i + 1, new_j}, {new_i, new_j}});
                }
                else if (parent_i != new_i + 1 || parent_j != new_j)
                {
                    // Cycle detected
                    return true;
                }
             }
        
        

               if(valid(new_i-1, new_j, n, m) && grid[new_i-1][new_j] == ch){
                if (!visited[new_i - 1][new_j])
                {
                    visited[new_i - 1][new_j] = true;
                    q.push({{new_i - 1, new_j}, {new_i, new_j}});
                }
                else if (parent_i != new_i - 1 || parent_j != new_j)
                {
                    // Cycle detected
                    return true;
                }
             }
          


             if(valid(new_i, new_j+1, n, m) && grid[new_i][new_j+1] == ch){
                if (!visited[new_i ][new_j+1])
                {
                    visited[new_i][new_j + 1] = true;
                    q.push({{new_i, new_j + 1}, {new_i, new_j}});
                }
                else if (parent_i != new_i || parent_j != new_j + 1)
                {
                    // Cycle detected
                    return true;
                }
                
             }
            
            
              if(valid(new_i, new_j-1, n, m) && grid[new_i][new_j-1] == ch){
                if (!visited[new_i ][new_j-1])
                {
                    visited[new_i ][new_j-1] = true;
                    q.push({{new_i, new_j-1}, {new_i, new_j}});
                }
                else if (parent_i != new_i  || parent_j != new_j-1)
                {
                    // Cycle detected
                    return true;
                }



             }
            
            }


        return false; // No cycle found
    }
    bool containsCycle(vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        ;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    if (bfs(grid, visited, n, m, i, j, -1, -1, grid[i][j]))
                    {
                        return true;
                    }
                }
            }
        }
    }
};