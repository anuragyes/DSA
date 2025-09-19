
int n, m;
long long totalSum = 0;

void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited,
         int visitedCount, int totalCells, long long currentCost, int prevValue) {
    
    // Check bounds and blocked/visited
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j])
        return;
    
    visited[i][j] = true;
    visitedCount++;
    
    if(prevValue != -1)
        currentCost += abs(grid[i][j] - prevValue); // cost from previous cell
    
    // If reached bottom-right and visited all unblocked cells
    if(i == n-1 && j == m-1 && visitedCount == totalCells) {
        totalSum += currentCost;
        visited[i][j] = false;
        return;
    }
    
    // Explore 4 directions
    dfs(grid, i+1, j, visited, visitedCount, totalCells, currentCost, grid[i][j]);
    dfs(grid, i-1, j, visited, visitedCount, totalCells, currentCost, grid[i][j]);
    dfs(grid, i, j+1, visited, visitedCount, totalCells, currentCost, grid[i][j]);
    dfs(grid, i, j-1, visited, visitedCount, totalCells, currentCost, grid[i][j]);
    
    // Backtrack
    visited[i][j] = false;
}







int Solution::solve(vector<vector<int> > &grid) {
     n = grid.size();
    m = grid[0].size();
    
    int totalCells = 0;
    for(auto &row : grid)
        for(auto val : row)
            if(val != 0) totalCells++;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    totalSum = 0;
    
    dfs(grid, 0, 0, visited, 0, totalCells, 0, -1);
    return totalSum;
}
