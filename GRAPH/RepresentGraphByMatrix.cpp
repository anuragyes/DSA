#include <iostream>
#include <vector>
using namespace std;



//  using unordered_map 
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // Define the adjacency list as an unordered_map
    unordered_map<int, vector<int>> adjList;

    // Add edges to the graph (undirected)
    adjList[0].push_back(1);
    adjList[0].push_back(4);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(2);
    adjList[4].push_back(0);

    // Print the adjacency list
    for (const auto& pair : adjList) {
        cout << "Node " << pair.first << " has neighbors: ";
        for (int neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}


//   adjancy list   using vector list 
/*
int main()
{

    int edges, vertex;

    vector<int> Adj[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u, v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";

        for (int j = 0; j < Adj[i].size(); j++)
        {
            cout << Adj[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
*/


// int main()
// {
//     int vertex, edges;
//     cin >> vertex >> edges; // Corrected input

//     // Create a vertex x vertex matrix initialized to 0
//     vector<vector<bool>> Adj(vertex, vector<bool>(vertex, 0));

//     int u, v;
//     // Read all edges and update the adjacency matrix
//     for (int i = 0; i < edges; i++)
//     {
//         cin >> u >> v; // Corrected input
//         Adj[u][v] = 1; // Mark the edge from u to v
//         Adj[v][u] = 1; // Mark the edge from v to u (for undirected graph)
//     }

//     // Now print the adjacency matrix after all edges are added
//     for (int i = 0; i < vertex; i++)
//     {
//         for (int j = 0; j < vertex; j++)
//         {
//             cout << Adj[i][j] << " "; // Print each element in the adjacency matrix
//         }
//         cout << endl; // Move to the next line after each row
//     }

//     return 0;
// }
