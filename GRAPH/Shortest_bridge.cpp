// #include <vector>
// #include <queue>

// using namespace std;

// //  You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// // An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// // You may change 0's to 1's to connect the two islands to form one island.

// // Return the smallest number of 0's you must flip to connect the two islands.

// class Solution
// {
// public:
//     int row;
//     int column;

//     bool valid(int i, int j)
//     {
//         return i >= 0 && j >= 0 && i < row && j < column;
//     }

//     void markFirstIsland(vector<vector<int>> &grid, queue<pair<int, int>> &q)
//     {
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < column; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     queue<pair<int, int>> temp;
//                     temp.push({i, j});
//                     grid[i][j] = 2;
//                     q.push({i, j});
//                     while (!temp.empty())
//                     {
//                         int x = temp.front().first;
//                         int y = temp.front().second;
//                         temp.pop();

//                         int dx[4] = {1, -1, 0, 0};
//                         int dy[4] = {0, 0, 1, -1};

//                         for (int d = 0; d < 4; d++)
//                         {
//                             int nx = x + dx[d];
//                             int ny = y + dy[d];
//                             if (valid(nx, ny) && grid[nx][ny] == 1)
//                             {
//                                 grid[nx][ny] = 2;
//                                 temp.push({nx, ny});
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }
//                     return; // Only mark the first island
//                 }
//             }
//         }
//     }

//     int shortestBridge(vector<vector<int>> &grid)
//     {
//         row = grid.size();
//         column = grid[0].size();
//         queue<pair<int, int>> q;

//         // Step 1: Mark the first island and fill the queue with its coordinates
//         markFirstIsland(grid, q);

//         // Step 2: Expand the island using BFS to find the shortest path to second island
//         int count = 0;
//         while (!q.empty())
//         {
//             int size = q.size();
//             while (size--)
//             {
//                 int first = q.front().first;
//                 int second = q.front().second;
//                 q.pop();

//                 int dx[4] = {1, -1, 0, 0};
//                 int dy[4] = {0, 0, 1, -1};

//                 for (int d = 0; d < 4; d++)
//                 {
//                     int ni = first + dx[d];
//                     int nj = second + dy[d];

//                     if (valid(ni, nj))
//                     {
//                         if (grid[ni][nj] == 1)
//                         {
//                             return count; // Found second island
//                         }
//                         else if (grid[ni][nj] == 0)
//                         {
//                             grid[ni][nj] = 2;
//                             q.push({ni, nj});
//                         }
//                     }
//                 }
//             }
//             count++;
//         }

//         return -1;
//     }
// };



