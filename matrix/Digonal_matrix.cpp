#include <iostream>

#include <vector>
using namespace std;


class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& matrix) {
          int n = matrix.size();
    
    // Check if the matrix is square if this is not square matrix  return false 
    for (int i = 0; i < n; i++) {
        if (matrix[i].size() != n) {
            return false;  // Not a square matrix
        }
    }

    // Check the elements for X-matrix properties
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || j == n - 1 - i) {  // Diagonal positions
                if (matrix[i][j] == 0) {
                    return false;  // Diagonal elements must be non-zero
                }
            } else {  // Non-diagonal positions
                if (matrix[i][j] != 0) {
                    return false;  // Non-diagonal elements must be zero
                }
            }
        }
    }
    return true;  // All checks passed, it's an X-matrix 
    }
};

