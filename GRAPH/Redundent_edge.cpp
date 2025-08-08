#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 */

class Solution {
public:
    //  using  dfs
    bool bfs(unordered_map<int, vector<int>>& adj, int u, int v) {
        queue<int> q;
        q.push(u);
        vector<bool> visited(1001, false);
        visited[u] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == v)
                return true;

            for (int neg : adj[node]) {

                if (!visited[neg]) {
                    visited[neg] = true;
                    q.push(neg);
                }
            }
        }

        return false;
    }
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u,
             int v) {
        if (u == v)
            return true;
        visited[u] = true;

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, neighbor, v)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size();

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> visited(n, false);
            //    dfs code
            // if (adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj,
            // visited, u, v )) {

            //          return edges[i];

            // }

            //  bfs code
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                bfs(adj, u, v)) {

                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
