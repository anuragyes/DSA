

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// only using dfs and after then reverse the stack

class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                dfs(adj[node][i], adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        stack<int> st;
        vector<int> ans;

        // Iterate over all nodes in case of disconnected components.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        // Pop elements from stack to get the topological order.
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
