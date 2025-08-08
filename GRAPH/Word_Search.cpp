class Solution {
public:
    bool dfs(int i, int j, int index, vector<vector<char>>& board, vector<vector<bool>>& visited, string& word) {
        // Base cases
        if (index == word.size()) return true;
        int n = board.size(), m = board[0].size();

        // Out of bounds or visited or mismatch
        if (i < 0 || i >= n || j < 0 || j >= m ||
            visited[i][j] || board[i][j] != word[index]) return false;

        visited[i][j] = true;

        // Explore 4 directions
        bool found = dfs(i + 1, j, index + 1, board, visited, word) ||
                     dfs(i - 1, j, index + 1, board, visited, word) ||
                     dfs(i, j + 1, index + 1, board, visited, word) ||
                     dfs(i, j - 1, index + 1, board, visited, word);

        visited[i][j] = false;  // Backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, visited, word)) return true;
                }
            }
        }
        return false;
    }
};
