// class Solution {
// public:
//     int count = 0;

//     bool boundary(int i, int j, int n, int m) {
//         return i >= 0 && j >= 0 && i < n && j < m;
//     }

//     void dfs(vector<vector<int>>& grid, int n, int m, int i, int j) {
//         // boundary check first
//         if (!boundary(i, j, n, m)) return;

//         // base case
//         if (i == n - 1 && j == m - 1) {
//             count++;
//             return;
//         }

//         // move down
//         dfs(grid, n, m, i + 1, j);

//         // move right
//         dfs(grid, n, m, i, j + 1);
//     }

//     int uniquePaths(int m, int n) {
//         // create m x n grid
//         vector<vector<int>> grid(n, vector<int>(m, 0));

//         dfs(grid, n, m, 0, 0);

//         return count;
//     }
// };

//    withou using grid 
// class Solution {
// public:
//     int count = 0;

//     void dfs(int i, int j, int n, int m) {
//         // Out of bounds
//         if (i >= n || j >= m) return;

//         // Reached destination
//         if (i == n - 1 && j == m - 1) {
//             count++;
//             return;
//         }

//         // Move down
//         dfs(i + 1, j, n, m);

//         // Move right
//         dfs(i, j + 1, n, m);
//     }

//     int uniquePaths(int m, int n) {
//         dfs(0, 0, n, m);
//         return count;
//     }
// };


class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& dp) {
        // boundary check
        if (i >= n || j >= m) return 0;

        // base case
        if (i == n - 1 && j == m - 1) return 1;

        // already computed
        if (dp[i][j] != -1) return dp[i][j];

        // move down and right
        int down = dfs(i + 1, j, n, m, dp);
        int right = dfs(i, j + 1, n, m, dp);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1)); // n rows, m cols
        return dfs(0, 0, n, m, dp);
    }
};
