#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    void shortestDistance(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // Initialize diagonal elements to 0 (distance from node to itself)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == -1)
                {
                    mat[i][j] = INT_MAX; // Mark unreachable nodes
                }
            }
        }

        // Set the diagonal to 0, distance from a node to itself is always 0
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }

        // Floyd-Warshall Algorithm: Update mat with the shortest paths
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // Avoid overflow by checking INT_MAX before adding
                    if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX)
                    {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        //   if you cant find the shortest distance of INT_MAX

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == INT_MAX)
                {
                    mat[i][j] = -1; // Mark unreachable nodes
                }
            }
        }
    }
};

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>> &dist, int V)
{
    // dist[][] will be the shortest distance matrix
    // We have the distances initialized and now applying the Floyd-Warshall logic

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If a shorter path exists, update the dist[][] matrix
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// Function to print the distance matrix
void printSolution(const vector<vector<int>> &dist, int V)
{
    cout << "The shortest distances between every pair of vertices are:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF "; // If no path exists
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Number of vertices
    int V = 4;

    // Initialize the distance matrix with large values for non-edges (INF)
    vector<vector<int>> dist = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}};

    // Apply Floyd-Warshall algorithm
    floydWarshall(dist, V);

    // Print the result
    printSolution(dist, V);

    return 0;
}
