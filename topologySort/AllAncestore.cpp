

#include <iostream>
using namespace std;
// optimal approch   using topological Sort

class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<set<int>> ancestors(n); // use set to keep sorted + unique

        // build adjacency list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto child : adj[node])
            {
                // add current node to child's ancestors
                ancestors[child].insert(node);

                // also add all ancestors of current node
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());

                // decrease indegree
                indegree[child]--;
                if (indegree[child] == 0)
                    q.push(child);
            }
        }

        // convert set → vector
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        return ans;
    }
};

// ----------------------------------------

// **brute force approch **
class Solution
{
public:
    vector<vector<int>> ans;

    void bfs(vector<vector<int>> &adj, int start, vector<bool> &visited, vector<int> &temp)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        temp.push_back(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        ans.assign(n, {});

        // Reverse graph: if u → v, then u is ancestor of v
        for (auto &element : edges)
        {
            int u = element[0];
            int v = element[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            vector<bool> visited(n, false);
            vector<int> temp;
            bfs(adj, i, visited, temp);
            sort(temp.begin(), temp.end()); // problem requires sorted order
            ans[i] = temp;
        }

        return ans;
    }
};
