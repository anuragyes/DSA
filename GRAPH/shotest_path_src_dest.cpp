
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void printcount(int n)
{
  //  base case
  int i = 1;

  if (i == n)
    return;

  cout << i << endl;
  
  printcount(i + 1);
}

int main()
{
  int n = 5;
  printcount(n);

  return 0;
}

// vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
// {
//   vector<int> adj[n];

//   // Creating the Adjacency List
//   for (int i = 0; i < m; i++)
//   {
//     adj[edges[i].first - 1].push_back(edges[i].second - 1);
//     adj[edges[i].second - 1].push_back(edges[i].first - 1);
//   }

//   s--; // Adjusting to 0-based indexing
//   t--; // Adjusting to 0-based indexing

//   vector<bool> visited(n, false); // Changed to bool and initialized with false
//   vector<int> distance(n, -1);    // Changed to -1 for not visited nodes
//   vector<int> parent(n, -1);      // Changed to -1 for not visited nodes
//   queue<int> q;

//   q.push(s);
//   visited[s] = true; // Marking the source node as visited
//   distance[s] = 0;   // Distance of source node is 0
//   parent[s] = -1;    // Parent of source node is NULL

//   while (!q.empty())
//   {
//     int node = q.front();
//     q.pop();

//     for (int i = 0; i < adj[node].size(); i++)
//     {
//       int neighbor = adj[node][i];
//       if (!visited[neighbor])
//       {
//         visited[neighbor] = true;
//         q.push(neighbor);
//         distance[neighbor] = distance[node] + 1;
//         parent[neighbor] = node;
//       }
//     }
//   }

//   vector<int> path;
//   while (t != -1)
//   {
//     path.push_back(t + 1);
//     t = parent[t];
//   }
//   reverse(path.begin(), path.end());
//   return path;
// }