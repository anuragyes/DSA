

//  prism algo  minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}

/*




class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {
      // Min-Heap (priority queue) to get the minimum edge weight
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

      vector<bool> vis(V, false); // To mark the nodes included in the MST
      int sum = 0;

      // Start with node 0, no parent (-1), and weight 0M-Coloring Problem
      pq.push({0, {0, -1}}); // {weight, {node, parent}}

      while (!pq.empty()) {
          int weight = pq.top().first;
          int node = pq.top().second.first;
          int parentNode = pq.top().second.second;
          pq.pop();

          if (vis[node]) continue; // Skip already visited node

          // Add this node to the MST
          vis[node] = true;
          sum += weight;

          // Explore the adjacent nodes
          for (auto& neighbor : adj[node]) {
              int adjNode = neighbor[0];  // Adjacent node
              int edgeWeight = neighbor[1];  // Edge weight

              // If adjacent node hasn't been visited, push it to the priority queue
              if (!vis[adjNode]) {
                  pq.push({edgeWeight, {adjNode, node}});
              }
          }
      }

      return sum; // Return the sum of weights of the MST
  }
};


*/