//   using topo Sort this is the original ans  provider 
class Solution {
    public:
        vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            vector<set<int>> ancestors(n); // Use set to avoid duplicates
    
            // Build adjacency list
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
            }
    
            // Topological sort using BFS (Kahn's algorithm)
            vector<int> indegree(n, 0);
            for (int u = 0; u < n; ++u) {
                for (int v : adj[u]) {
                    indegree[v]++;
                }
            }
    
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (indegree[i] == 0)
                    q.push(i);
            }
    
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    // Add current node and its ancestors to the neighbor's ancestor
                    // set
                    ancestors[neighbor].insert(node);
                    for (int anc : ancestors[node]) {
                        ancestors[neighbor].insert(anc);
                    }
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0)
                        q.push(neighbor);
                }
            }
    
            // Convert sets to sorted vectors
            vector<vector<int>> res(n);
            for (int i = 0; i < n; ++i) {
                res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            }
    
            return res;
        }
    };
 

//   using dfs but TLT found 

class Solution {
    public:
        void dfs(int node, int origin, vector<vector<int>>& revAdj, vector<set<int>>& ancestors, vector<bool>& visited) {
            visited[node] = true;
            for (int neighbor : revAdj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, origin, revAdj, ancestors, visited);
                }
                ancestors[origin].insert(neighbor);
                ancestors[origin].insert(ancestors[neighbor].begin(), ancestors[neighbor].end());
            }
        }
    
        vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
            // Step 1: Build reverse adjacency list
            vector<vector<int>> revAdj(n);
            for (auto& edge : edges) {
                revAdj[edge[1]].push_back(edge[0]);  // Reverse edge direction
            }
    
            // Step 2: Ancestors storage
            vector<set<int>> ancestors(n);
    
            // Step 3: Run DFS from each node in reverse graph
            for (int i = 0; i < n; ++i) {
                vector<bool> visited(n, false);
                dfs(i, i, revAdj, ancestors, visited);
            }
    
            // Step 4: Convert sets to sorted vectors
            vector<vector<int>> result(n);
            for (int i = 0; i < n; ++i) {
                result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            }
    
            return result;
        }
    };
    