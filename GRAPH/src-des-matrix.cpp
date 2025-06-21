/*Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall (blocked cell which we cannot traverse).
Note: There are only a single source and a single destination.*/
#include <vector>
#include <queue>
using namespace std;

const int rowDirections[] = {0, 1, 0, -1};
const int colDirections[] = {1, 0, -1, 0};

// Function to check if a cell is within grid boundaries and not a wall
bool isValid(int x, int y, int n, vector<vector<int>>& grid) {
    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0 );
}

class Solution
{
public:
    // Function to find whether a path exists from the source to destination
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
       
        queue<pair<int, int>> q;

        pair<int, int> source, destination;
        
        // Finding source and destination nodes
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    source = {i, j};
                } else if(grid[i][j] == 2) {
                    destination = {i, j};
                }
            }
        }

        q.push(source);
        grid[source.first][source.second] = 0;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            // If we reach the destination, return true
            if (current == destination) {
                return true;
            }

            // Explore all possible directions
            for (int i = 0; i < 4; ++i) {
                int newRow = current.first + rowDirections[i];
                int newCol = current.second + colDirections[i];

                if (isValid(newRow, newCol, n, grid)) {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 0;
                }
            }
        }

        // If BFS completes without finding the destination
        return false;
    }
};