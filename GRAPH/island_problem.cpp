#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int row;
    int column;

    int r[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int c[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < row && j >= 0 && j < column;
    }
    int island(vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        int count = 0;

        row = grid.size();
        column = grid[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] = '1')
                {
                    count++;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while (!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for (int k = 0; k < 8; k++)
                        {

                            if (valid(new_i + r[k], new_j + c[k]) && grid[new_i + r[k]][new_j + c[k]] == '1')
                            {
                                grid[new_i + r[k]][new_j + c[k]] = '0';
                                q.push(make_pair(new_i + r[k], new_j + c[k]));
                            }
                        }
                    }
                }
            }

        return count;
    }
};

// eight direction

class Solution
{
public:
    // Function to find the number of islands.
    int columns;
    int rows;

    bool valid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        columns = grid[0].size();
        rows = grid.size();
        queue<pair<int, int>> q;

        int count = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (grid[i][j] == '1')
                {
                    q.push({i, j});
                    grid[i][j] = '0';
                    count++;
                    while (!q.empty())
                    {
                        int firstnode = q.front().first;
                        int secondnode = q.front().second;
                        q.pop();

                        // Assuming `grid` is a 2D grid similar to `grid` and `valid` is a function checking grid boundaries.

                        if (valid(firstnode - 1, secondnode) && grid[firstnode - 1][secondnode] == '1')
                        {
                            grid[firstnode - 1][secondnode] = '0';
                            q.push({firstnode - 1, secondnode});
                        }

                        if (valid(firstnode + 1, secondnode) && grid[firstnode + 1][secondnode] == '1')
                        {
                            grid[firstnode + 1][secondnode] = '0';
                            q.push({firstnode + 1, secondnode});
                        }

                        if (valid(firstnode, secondnode - 1) && grid[firstnode][secondnode - 1] == '1')
                        {
                            grid[firstnode][secondnode - 1] = '0';
                            q.push({firstnode, secondnode - 1});
                        }

                        if (valid(firstnode, secondnode + 1) && grid[firstnode][secondnode + 1] == '1')
                        {
                            grid[firstnode][secondnode + 1] = '0';
                            q.push({firstnode, secondnode + 1});
                        }

                        // Adding diagonal directions
                        if (valid(firstnode - 1, secondnode - 1) && grid[firstnode - 1][secondnode - 1] == '1')
                        {
                            grid[firstnode - 1][secondnode - 1] = '0';
                            q.push({firstnode - 1, secondnode - 1});
                        }

                        if (valid(firstnode - 1, secondnode + 1) && grid[firstnode - 1][secondnode + 1] == '1')
                        {
                            grid[firstnode - 1][secondnode + 1] = '0';
                            q.push({firstnode - 1, secondnode + 1});
                        }

                        if (valid(firstnode + 1, secondnode - 1) && grid[firstnode + 1][secondnode - 1] == '1')
                        {
                            grid[firstnode + 1][secondnode - 1] = '0';
                            q.push({firstnode + 1, secondnode - 1});
                        }

                        if (valid(firstnode + 1, secondnode + 1) && grid[firstnode + 1][secondnode + 1] == '1')
                        {
                            grid[firstnode + 1][secondnode + 1] = '0';
                            q.push({firstnode + 1, secondnode + 1});
                        }
                    }
                }

        return count;
    }
};