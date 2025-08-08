/*You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.*/


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

       

        // Build graph and indegree
        for (auto& edge : edges) { 
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // Initialize ancestor sets
        vector<set<int>> ancestors(n);

        // Kahn's algorithm for topological sort
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                // Add node and its ancestors to neighbor
                ancestors[neighbor].insert(node);

                ancestors[neighbor].insert(ancestors[node].begin(),
                ancestors[node].end());

                // Decrease indegree and push to queue if 0
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Convert sets to sorted vectors
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i)
            result[i] = vector<int>(ancestors[i].begin(),
            ancestors[i].end());

        return result;
    }
};