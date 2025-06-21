#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort each diagonal of the matrix
vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size();    // number of rows
    int n = mat[0].size(); // number of columns

    // Helper function to collect and sort the diagonal starting from mat[r][c]
    auto sortDiagonal = [&](int r, int c)
    {
        vector<int> diagonal;

        // Collect all elements in the diagonal
        int i = r, j = c;
        while (i < m && j < n)
        {
            diagonal.push_back(mat[i][j]);
            i++;
            j++;
        }

        // Sort the diagonal elements
        sort(diagonal.begin(), diagonal.end());

        // Place the sorted diagonal back into the matrix
        i = r, j = c;
        int idx = 0;
        while (i < m && j < n)
        {
            mat[i][j] = diagonal[idx++];
            i++;
            j++;
        }
    };

    // Sort diagonals starting from the first row
    for (int c = 0; c < n; c++)
    {
        sortDiagonal(0, c);
    }

    // Sort diagonals starting from the first column
    for (int r = 1; r < m; r++)
    {
        sortDiagonal(r, 0);
    }

    return mat;
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}};

    cout << "Original Matrix:" << endl;
    printMatrix(mat);

    vector<vector<int>> sortedMat = diagonalSort(mat);

    cout << "\nSorted Matrix:" << endl;
    printMatrix(sortedMat);

    return 0;
}
