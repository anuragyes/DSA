class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
     int rows;
    int columns;

    bool valid(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }

    int orangesRotting(vector<vector<int>>& grid) {
rows = grid.size();
        columns = grid[0].size();
        if(grid.empty()) return 0;

        queue<pair<int, int>> q;
        int timer = -1; // Initially -1 since we start counting after the first push

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
         if(q.empty()){
              return 0;
         }

        while (!q.empty()) {
            timer++;
            int orangelevel = q.size();

            while (orangelevel--) {
                int firstnode = q.front().first;
                int secondnode = q.front().second;
                q.pop();

                // Check all 4 possible directions directly
                if (valid(firstnode - 1, secondnode) && grid[firstnode - 1][secondnode] == 1) {
                    grid[firstnode - 1][secondnode] = 2;
                    q.push({firstnode - 1, secondnode});
                }
                if (valid(firstnode + 1, secondnode) && grid[firstnode + 1][secondnode] == 1) {
                    grid[firstnode + 1][secondnode] = 2;
                    q.push({firstnode + 1, secondnode});
                }
                if (valid(firstnode, secondnode - 1) && grid[firstnode][secondnode - 1] == 1) {
                    grid[firstnode][secondnode - 1] = 2;
                    q.push({firstnode, secondnode - 1});
                }
                if (valid(firstnode, secondnode + 1) && grid[firstnode][secondnode + 1] == 1) {
                    grid[firstnode][secondnode + 1] = 2;
                    q.push({firstnode, secondnode + 1});
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return timer;
    }
};