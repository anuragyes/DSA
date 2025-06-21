
#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution
{
public:
  // Function to detect cycle in an undirected graph.

  bool solve(int node, int parent, vector<int> adj[], vector<bool> &visited)
  {

    //   staring with first node
    visited[node] = 1;
    //  check its neghibour
    for (int i = 0; i < adj[node].size(); i++)
    {
      //   case first
      if (parent == adj[node][i])
        continue;
      //  second case if alredy visited mark it cycle
      if (visited[adj[node][i]])
        return 1;
      //  last and third case when we have not found any cycle return 0
      if (solve(adj[node][i], node, adj, visited))
        return 1;
    }
    return 0;
  }
  bool isCycle(int V, vector<int> adj[])
  {
    vector<bool> visited(V, 0);
    //   visited for not contected  node
    for (int i = 0; i < V; i++)
    {
      if (!visited[i] && solve(i, -1, adj, visited))
      {
        return 1;
      }
    }
    return 0;
  }
};

// now using bsf
/*
    bool bsf(int node, vector<int> adj[], vector<bool> &visited)
{
  queue<pair<int, int>> q;
  visited[vertex] = 1;
  q.push(make_pair(vertex, -1));
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (int i = 0; i < adj[node].size(); i++)
    {
      if (parent == adj[node][i])
        continue;
      if (visited[adj[node][i]])
        return 1;
      visited[adj[node][i]] = 1;
      q.push(make_pair(adj[node][i], node));
    }
  }
  return 0;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<bool> visited(V, 0);

  for (int i = 0; i < V; i++)
  {
    if (!visited[i] && bsf(i, adj, visited))
    {
      return 1;
    }
  }
  return 0;
}
*/