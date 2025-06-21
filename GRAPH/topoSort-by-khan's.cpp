#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{

    // khan's algo
    queue<int> q;
    vector<int> ans;
    vector<int> Indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < adj[i].size(); j++)
            Indegree[adj[i][j]]++;

    //   push all the node of zero degree
    for (int i = 0; i < V; i++)
        if (!Indegree[i])
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            Indegree[adj[node][j]]--;
            if (Indegree[adj[node][j]] == 0)
            {
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}