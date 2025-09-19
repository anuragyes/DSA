#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int n, m;

    bool dfs(vector<vector<char>> &board, string &word, int idx, int i, int j, vector<vector<bool>> &visited)
    {
        // base case: full word found
        if (idx == word.size())
            return true;

        // boundary & visited & mismatch check
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || board[i][j] != word[idx])
            return false;

        // mark visited
        visited[i][j] = true;

        // explore 4 directions
        bool found = dfs(board, word, idx + 1, i + 1, j, visited) ||
                     dfs(board, word, idx + 1, i - 1, j, visited) ||
                     dfs(board, word, idx + 1, i, j + 1, visited) ||
                     dfs(board, word, idx + 1, i, j - 1, visited);

        // backtrack
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
