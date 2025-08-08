// class Solution {
// public:
//     // DFS to count reachable nodes, avoiding restricted ones
//     int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& restrictedSet) {
//         if (restrictedSet.count(node)) return 0;  // Can't visit restricted nodes

//         visited[node] = true;
//         int count = 1;  // Count the current node

//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor] && !restrictedSet.count(neighbor)) {
//                 count += dfs(neighbor, adj, visited, restrictedSet);
//             }
//         }

//         return count;
//     }

//     int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
//         // Build adjacency list
//         vector<vector<int>> adj(n);
//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<bool> visited(n, false);
//         unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

//         // Start DFS from node 0
//         return dfs(0, adj, visited, restrictedSet);
//     }
// };



class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Store restricted nodes in a set for O(1) lookup
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

        // Step 3: Setup visited array and queue for BFS
        vector<bool> visited(n, false);
        queue<int> q;

        // Step 4: Start BFS from node 0 if it's not restricted
        if (restrictedSet.count(0)) return 0;

        q.push(0);
        visited[0] = true;
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++; // Count the current node

            for (int neighbor : adj[node]) {
                if (!visited[neighbor] && !restrictedSet.count(neighbor)) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return count;
    }
};

/*There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

 

Example 1:


Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.*/