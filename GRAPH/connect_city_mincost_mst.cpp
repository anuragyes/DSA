#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
    // Step 1: Build the adjacency list
    vector<vector<pii>> adj(n+1 ); // using 1-based indexing for cities

    for (const vector<int> &edge : connections)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // Step 2: Prim's Algorithm
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n+1, false);

    int totalCost = 0;
    int count = 0;

    pq.push({0, 1}); // Start from node 1

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        totalCost += weight;
        count++;

        for (const pii &neighbor : adj[node])
        {
            int w = neighbor.first;
            int next = neighbor.second;

            if (!visited[next])
            {
                pq.push({w, next});
            }
        }
    }

    // Step 3: If not all nodes are visited, return -1
    if (count != n)
        return -1;

    return totalCost;
}
