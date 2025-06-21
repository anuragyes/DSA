#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//   brute force approch
/*

class Solution {
public:
    int n, m;
    int minEffort = INT_MAX;

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& visited, int currentMaxDiff) {
        // Base case: reach destination
        if (i == n - 1 && j == m - 1) {
            minEffort = min(minEffort, currentMaxDiff);
            return;
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        visited[i][j] = true;

        for (auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
                int diff = abs(heights[i][j] - heights[ni][nj]);
                dfs(heights, ni, nj, visited, max(currentMaxDiff, diff));
            }
        }

        visited[i][j] = false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(heights, 0, 0, visited, 0);
        return minEffort;
    }
};



*/

class Solution
{
public:
    int n, m;

    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool canReach(vector<vector<int>> &heights, int maxEffort)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == m - 1)
                return true;

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny])
                {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    if (diff <= maxEffort)
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // n = heights.size();
        // m = heights[0].size();

        // int left = 0, right = 1e6, ans = 0;

        // while (left <= right) {
        //     int mid = left + (right - left) / 2;
        //     if (canReach(heights, mid)) {
        //         ans = mid;
        //         right = mid - 1; // Try smaller max effort
        //     } else {
        //         left = mid + 1; // Increase effort
        //     }
        // }

        // return ans;
        int n = heights.size();
        int m = heights[0].size();

        // Min-heap priority queue: {effort, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Distance array to store minimum effort to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!pq.empty())
        {
            auto [effort, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1)
                return effort; // Reached destination

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    int currEffort = abs(heights[x][y] - heights[nx][ny]);
                    int maxEffort = max(effort, currEffort);

                    if (dist[nx][ny] > maxEffort)
                    {
                        dist[nx][ny] = maxEffort;
                        pq.push({maxEffort, nx, ny});
                    }
                }
            }
        }

        return 0; // Shouldn't reach here
    }
};