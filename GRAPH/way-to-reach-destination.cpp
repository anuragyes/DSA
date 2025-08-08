#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
vector<int> countWaysToDestination(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n); // Adjacency list to store graph
    for (const auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    // Dijkstra's algorithm variables
    vector<int> dist(n, INT_MAX);  // Distance to each node
    vector<int> ways(n, 0);        // Number of ways to reach each node with the shortest time
    dist[0] = 0;                   // Start at node 0
    ways[0] = 1;                   // Only one way to be at the starting point
    
    // Min-heap to process nodes (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Starting point with distance 0

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we find the same distance again, skip processing
        if (current_dist > dist[u]) {
            continue;
        }

        // Process each neighbor
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int time = neighbor.second;

            // If a shorter path to v is found
            if (dist[u] + time < dist[v]) {
                dist[v] = dist[u] + time;
                ways[v] = ways[u];  // Reset ways to reach v to ways to reach u
                pq.push({dist[v], v});
            } 
            // If a path with the same shortest time to v is found
            else if (dist[u] + time == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;  // Add the ways to reach u to ways to reach v
            }
        }
    }

    return ways; // Return the number of ways to reach all nodes
}
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<int> ways = countWaysToDestination(n, roads);
            
    return ways[n - 1];  
    }
};