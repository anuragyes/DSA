// #include <bits/stdc++.h>
// //  brute force approch
// /*
// void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//     // set all non-zero elements as -1 in the row i:
//     for (int j = 0; j < m; j++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }


// void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//     // set all non-zero elements as -1 in the col j:
//     for (int i = 0; i < n; i++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//          // Set -1 for rows and cols
//     // that contains 0. Don't mark any 0 as -1:

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }
//         }
//     }

//     // Finally, mark all -1 as 0:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == -1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     return matrix;
// }

// */

// //  better approch

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//   int row[n] = {0}; // row array
//   int col[m] = {0}; // col array
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (matrix[i][j] == 0) {
//        row[i] = 1;
//         col[j] = 1;
//       }
//     }
//   }

//   // Traverse the matrix:
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (matrix[i][j] == 0) {
//         // mark ith index of row wih 1:
//         row[i] = 1;

//         // mark jth index of col wih 1:
//         col[j] = 1;
//       }
//     }
//   }

//   // Finally, mark all (i, j) as 0
//   // if row[i] or col[j] is marked with 1.
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (row[i] || col[j]) {
//         matrix[i][j] = 0;
//       }
//     }
//   }

//   return matrix;
// }


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.






/*
 vector<bool>visisted(N , 0 );

  queue<Node*>q;
  q.push(0);
  visited[0]=true;

   while(!q.empty()){
    Node* node = q.front();
    q.pop();
     ans.push_back(node->data);
     if(node->left){
     q.push(node->left);
     }
      if(node->right){
      q.push(node->right);
      }
   }
  */
