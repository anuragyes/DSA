#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool solve(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited)
    {
        visited[node] = true;  // Mark node as visited in the DFS
        path[node] = true;     // Mark node as part of the current recursion stack
        
        for (int i = 0; i < adj[node].size(); i++)
        {
            // If the node is already in the current recursion stack, we found a cycle
            if (path[adj[node][i]])
                return true;

            // If the node has already been visited (fully processed), skip it
            if (visited[adj[node][i]])
                continue;


                // if (!visited[adj[node][i]])
                // visited[adj[node][i]]= true;

            // Recursively explore the neighbor
            if (solve(adj[node][i], adj, path, visited))
                return true;
        }
        
        // After exploring all neighbors, mark the node as not part of the recursion stack
        path[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> path(V, false);   // Tracks nodes in the current recursion stack
        vector<bool> visited(V, false); // Tracks fully processed nodes
        
        for (int i = 0; i < V; i++)
        {
            // If node is not visited and solve() returns true, a cycle is detected
            if (!visited[i] && solve(i, adj, path, visited))
                return true;
        }
        return false;  // No cycle found
    }
};

// Driver code
int main()
{
    Solution sol;
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(3);

    if (sol.isCyclic(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
