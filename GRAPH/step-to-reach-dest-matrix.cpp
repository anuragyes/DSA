#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int column[4] = {0, 0, 1, -1};
    
    bool valid(int i, int j, int N, int M) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
    
    int shortestDistance(int N, int M, vector<vector<int>> &A, int X, int Y) {
        if (A[0][0] == 0 || A[X][Y] == 0) return -1; // Check if start or end are blocked
        
        int step = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0; // Mark start as visited
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if (i == X && j == Y) return step;
                
                for (int k = 0; k < 4; k++) {
                    int new_i = i + row[k];
                    int new_j = j + column[k];
                    
                    if (valid(new_i, new_j, N, M) && A[new_i][new_j] == 1) {
                        A[new_i][new_j] = 0; // Mark as visited
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;
        }
        
        return -1; // If we exit the loop, no path was found
    }
};
