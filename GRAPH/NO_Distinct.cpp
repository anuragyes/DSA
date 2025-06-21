class Solution {
    public:
        int row, col;
        
        bool valid(int i, int j) {
            return (i >= 0 && i < row && j >= 0 && j < col);
        }
    
        void bfs(int x, int y, vector<vector<int>>& grid, vector<pair<int, int>>& shape) {
            queue<pair<int, int>> q;
            q.push({x, y});
            grid[x][y] = 0;  // mark as visited
            shape.push_back({0, 0});
            
            vector<int> dx = {0, 0, 1, -1};
            vector<int> dy = {1, -1, 0, 0};
            
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
    
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
    
                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        q.push({ni, nj});
                        grid[ni][nj] = 0;
    
                        // record relative position
                        shape.push_back({ni - x, nj - y});
                    }
                }
            }
        }
    
        int countDistinctIslands(vector<vector<int>>& grid) {
            row = grid.size();
            col = grid[0].size();
            set<vector<pair<int, int>>> shapes;
    
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (grid[i][j] == 1) {
                        vector<pair<int, int>> shape;
                        bfs(i, j, grid, shape);
                        shapes.insert(shape);
                    }
                }
            }
            return shapes.size();
        }
    };
    