
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int n;
    int m;

    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Push all 0s into the queue and mark them as 0 in ans
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            int new_i = q.front().first;
            int new_j = q.front().second;
            q.pop();

            // Down
            if (valid(new_i + 1, new_j) && ans[new_i + 1][new_j] == -1)
            {
                ans[new_i + 1][new_j] = ans[new_i][new_j] + 1;
                q.push({new_i + 1, new_j});
            }

            // Up
            if (valid(new_i - 1, new_j) && ans[new_i - 1][new_j] == -1)
            {
                ans[new_i - 1][new_j] = ans[new_i][new_j] + 1;
                q.push({new_i - 1, new_j});
            }

            // Right
            if (valid(new_i, new_j + 1) && ans[new_i][new_j + 1] == -1)
            {
                ans[new_i][new_j + 1] = ans[new_i][new_j] + 1;
                q.push({new_i, new_j + 1});
            }

            // Left
            if (valid(new_i, new_j - 1) && ans[new_i][new_j - 1] == -1)
            {
                ans[new_i][new_j - 1] = ans[new_i][new_j] + 1;
                q.push({new_i, new_j - 1});
            }
        }

        return ans;
    }
};
