#include <bits/stdc++.h>
#include <set>
using namespace std;
class solution
{

  vector<int> system(vector<int> adj[], int V)
  {

    queue<int> q;
    // make a vector for track to find visted or not
    vector<bool> visted(V, 0);
    // store the ans
    vector<int> ans;
    // push firstly index zero 0
    q.push(0);
    //   mark true for zero
    visted[0] = 1;

    //  pop the element while q will not become empty

    while (!q.empty())
    {
      // get front node of queue
      int node = q.front();
      // pop the element from queue
      q.pop();
      // push the poped element into ans vector
      ans.push_back(node);
      // now check negobure element of zero index
      for (int i = 0; i < adj[node].size(); i++)
      {
        if (!visted[adj[node][i]])
        {
          visted[adj[node][i]] = 1;
          q.push(adj[node][i]);
        }
      }
    }
    return ans;
  }
};
