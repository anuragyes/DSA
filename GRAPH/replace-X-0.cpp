
//   first step : push all the zero of bounday elements into queue 
//    now all the zero of bounday elements connected with other zeroes make it T 
//    second step : after this travers all the grid and make 0 to X 
//    third step : t make again 0 and return grid



// class Solution {


// public:
//     int row;
//     int column;

//     // Helper function to check if a cell is within grid bounds
//     bool valid(int i, int j) {
//         return i >= 0 && i < row && j >= 0 && j < column;
//     }

//     // Main function to fill the grid
//     vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
//         row = n;
//         column = m;
//         queue<pair<int, int>> q;

//         // Process the first and last rows
//         for (int i = 0; i < column; i++) {
//             if (mat[0][i] == 'O') {
//                 q.push({0, i});
//                 mat[0][i] = 't'; // Temporary marker
//             }
//             if (mat[row-1][i] == 'O') {
//                 q.push({row-1, i});
//                 mat[row-1][i] = 't'; // Temporary marker
//             }
//         }

//         // Process the first and last columns
//         for (int i = 1; i < row - 1; i++) {
//             if (mat[i][0] == 'O') {
//                 q.push({i, 0});
//                 mat[i][0] = 't'; // Temporary marker
//             }
//             if (mat[i][column-1] == 'O') {
//                 q.push({i, column-1});
//                 mat[i][column-1] = 't'; // Temporary marker
//             }
//         }

//         // BFS to mark all reachable 'O's from the boundary
//         while (!q.empty()) {
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();

//             // Check all four possible directions
//             if (valid(i - 1, j) && mat[i - 1][j] == 'O') {
//                 mat[i - 1][j] = 't'; // Temporary marker
//                 q.push({i - 1, j});
//             }
//             if (valid(i + 1, j) && mat[i + 1][j] == 'O') {
//                 mat[i + 1][j] = 't'; // Temporary marker
//                 q.push({i + 1, j});
//             }
//             if (valid(i, j - 1) && mat[i][j - 1] == 'O') {
//                 mat[i][j - 1] = 't'; // Temporary marker
//                 q.push({i, j - 1});
//             }
//             if (valid(i, j + 1) && mat[i][j + 1] == 'O') {
//                 mat[i][j + 1] = 't'; // Temporary marker
//                 q.push({i, j + 1});
//             }
//         }

//         // Now convert all 'O' to 'X' and all 't' back to 'O'
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < column; j++) {
//                 if (mat[i][j] == 'O') {
//                     mat[i][j] = 'X';
//                 } else if (mat[i][j] == 't') {
//                     mat[i][j] = 'O';
//                 }
//             }
//         }

//         return mat;
//     }
// };
