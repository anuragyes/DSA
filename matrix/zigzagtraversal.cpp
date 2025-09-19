#include <bits/stdc++.h>
using namespace std;

vector<int> diagonalZigzagTraversal(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;
    
    for (int d = 0; d < m + n - 1; ++d) {
        vector<int> intermediate;

        int row = (d < n) ? 0 : d - n + 1;
        int col = (d < n) ? d : n - 1;

        while (row < m && col >= 0) {
            intermediate.push_back(matrix[row][col]);
            row++;
            col--;
        }

        // Reverse every other diagonal to get zigzag
        if (d % 2 == 0) {
            reverse(intermediate.begin(), intermediate.end());
        }

        result.insert(result.end(), intermediate.begin(), intermediate.end());
    }

    return result;
}
