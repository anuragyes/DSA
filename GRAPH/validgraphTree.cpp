class Solution {
public:

    bool BFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
        queue<pair<int, int>> q; // {node, parent}
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
              int node = q.front().first;
              int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    // A visited node that's not the parent → cycle
                    return true;
                }
            }
        }

        return false; // No cycle found
    }

    int isTree(int n, int m, vector<vector<int>> &adj) {
        // Condition 1: Must have exactly n - 1 edges
        if (m != n - 1) return false;

        vector<bool> visited(n, false);
        
        // Condition 2: No cycle  dected cycle ?
        if (BFS(0, adj, visited)) return false;

        // Condition 3: Fully connected
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
