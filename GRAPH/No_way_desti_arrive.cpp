#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& element : roads) {
            int u = element[0];
            int v = element[1];
            int w = element[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {dist, node}

        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distance[node]) continue; // skip outdated entry

            for (auto& it : adj[node]) {
                int adjnode = it.first;
                long long weight = it.second;

                // Found a shorter path
                if (dist + weight < distance[adjnode]) {
                    distance[adjnode] = dist + weight;
                    pq.push({distance[adjnode], adjnode});
                    ways[adjnode] = ways[node] % MOD;
                }
                // Found an equal shortest path
                else if (dist + weight == distance[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
