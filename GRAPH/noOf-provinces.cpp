
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    void dsf(int node, vector<int> adjlist[], vector<bool> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            if (!visited[adjlist[node][i]])
            {
                dsf(adjlist[node][i], adjlist, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<int> adjlist[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dsf(i, adjlist, visited);
            }
        }
        return cnt;
    }
};
