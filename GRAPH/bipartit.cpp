#include <vector>
#include <queue>
using namespace std;

// class Solution
// {
// public:
//     bool isBipartite(int V, vector<int> adj[])
//     {
//         vector<int> color(V, -1);
//         queue<int> q;

//         for (int i = 0; i < V; i++)
//         {
//             if (color[i] == -1)
//             {
//                 color[i] = 0;
//                 q.push(i);

//                 while (!q.empty())
//                 {
//                     int node = q.front();
//                     q.pop();

//                     for (int j = 0; j < adj[node].size(); j++)
//                     {
//                         int neighbor = adj[node][j];
//                         if (color[neighbor] == -1)
//                         {
//                             color[neighbor] = 1 - color[node]; // Assign opposite color
//                             q.push(neighbor);
//                         }
//                         else
//                         {
//                             if (color[node] == color[neighbor])
//                                 return false; // Graph is not bipartite
//                         }
//                     }
//                 }
//             }
//         }
//         return true; // Graph is bipartite
//     }
// };



