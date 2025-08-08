class Solution {
public:
    int rows;
    int columns;

    bool valid(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        rows = grid.size();
        columns = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int timer = -1;

        // Push all rotten oranges and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges, time is 0
        if (fresh == 0) return 0;

        // If no rotten orange to start the process
        if (q.empty()) return -1;

        while (!q.empty()) {
            int orangelevel = q.size();
            timer++;

            while (orangelevel--) {
                int firstnode = q.front().first;
                int secondnode = q.front().second;
                q.pop();

                // Check all 4 directions
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto [dx, dy] : directions) {
                    int ni = firstnode + dx;
                    int nj = secondnode + dy;

                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return fresh == 0 ? timer : -1;
    }
};
