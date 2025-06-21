
   

void dfs(int node, const vector<vector<int>>& adj, vector<vector<int>>& res, vector<int>& ans, vector<bool>& visited) {
        visited[node] = true;
        ans.push_back(node);
        
        if (node == adj.size() - 1) { // If we've reached the target node
            res.push_back(ans); // Store the current path
        } else {
            for (int i = 0; i < adj[node].size(); i++) {
                int nextNode = adj[node][i];
                if (!visited[nextNode]) {
                    dfs(nextNode, adj, res, ans, visited);
                }
            }
        }

        ans.pop_back(); // Backtrack
        visited[node] = false; // Unmark the node for other paths
    };
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> visited(graph.size(), false); // Initialize visited array with the size of the graph
        dfs(0, graph, res, ans, visited); // Start DFS from node 0
        return res;

    }
};