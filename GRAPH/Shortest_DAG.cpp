

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // Step 1: Create adjacency list and calculate in-degrees
        vector<vector<pair<int, int>>> adj(V); // (node, weight)
        vector<int> inDegree(V, 0);            // To store in-degrees for topological sort

        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            inDegree[v]++;
        }

        // Step 2: Perform Topological Sort (Kahn's Algorithm)
        queue<int> q;
        vector<int> topoOrder;

        // Push all vertices with in-degree 0 into the queue
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            // Process all the neighbors of 'u'
            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Step 3: Initialize distances and perform relaxation
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Distance from the source vertex to itself is 0

        for (int u : topoOrder)
        {
            if (dist[u] != INT_MAX)
            {
                // Relax all edges from u
                for (auto &neighbor : adj[u])
                {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Step 4: Replace INT_MAX with -1 where nodes are not reachable
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1; // Not reachable
            }
        }

        return dist;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {2, 3, 7}, {2, 4, 4}, {3, 4, 2}};
    int V = 5;            // Number of vertices
    int E = edges.size(); // Number of edges

    vector<int> result = solution.shortestPath(V, E, edges);

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Vertex " << i << ": " << result[i] << endl;
    }

    return 0;
}
