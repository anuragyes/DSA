#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(int n, vector<string> &board, int i, int j, vector<bool> &column)
    {
        // Check upper left diagonal
        int row = i;
        int columnIndex = j;

        while (row > -1 && columnIndex > -1)
        {
            if (board[row][columnIndex] == 'Q')
            {
                return false;
            }
            row--;
            columnIndex--;
        }

        // Check upper right diagonal
        row = i;
        columnIndex = j;
        while (row > -1 && columnIndex < n)
        {
            if (board[row][columnIndex] == 'Q')
            {
                return false;
            }
            row--;
            columnIndex++;
        }

        // Check the column itself
        if (column[j])
        {
            return false;
        }

        return true;
    }

    void helper(int n, vector<vector<string>> &ans, vector<bool> &column, int row, vector<string> &board)
    {
        // Base condition: If all rows are filled, add to the result
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column of the current row
        for (int i = 0; i < n; i++)
        {
            if (!column[i] && check(n, board, row, i, column))
            {
                column[i] = true;
                board[row][i] = 'Q';
                helper(n, ans, column, row + 1, board);
                column[i] = false;   // Backtrack
                board[row][i] = '.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;   
        vector<string> board(n, string(n, '.')); // Initialize the board with '.' characters
        vector<bool> column(n, false);           // Track columns where queens are placed

        helper(n, ans, column, 0, board); // Start the backtracking from row 0
        return ans;
    }
};

int main()
{
    return 0;
}