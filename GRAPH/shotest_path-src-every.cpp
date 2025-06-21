

#include <iostream>
using namespace std;
#include <queue>
#include <vector>
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {

        vector<int> adj[N];
        // Creating the Adjacency List
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> distance(N, -1);
        vector<bool> visited(N, 0);

        queue<int> q;
        q.push(src);
        distance[src] = 0;
        visited[src] = 1;
        while (!q.empty())
        {

            int node = q.front();
            q.pop();
            for (int i = 0; i < adj[node].size(); i++)
            {
                if (visited[adj[node][i]])
                {
                    continue;
                }
                else
                {

                    visited[adj[node][i]] = 1; // else part
                    q.push(adj[node][i]);

                    distance[adj[node][i]] = distance[node] + 1;
                }
            }
        }

        return distance;
    }
};

//   second method to solve
/*

         // code here
        vector<vector<int>>adj(N);
        // Creating the Adjacency List
        for(int i = 0 ; i < M ; i++ )
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(N,INT_MAX);
        //dist[src] = 0;

        // INT_MAX  => Unvisited, any other value => Visited
        // BFS will be a better option in this question

        queue<int>q;
        q.push(src);
        int val = 0;
        while(!q.empty())
        {
            int n = q.size(); // Size of the current Queue
            for(int i = 0 ; i < n ; i++ )
            {
                int node = q.front();
                q.pop();
                dist[node] = min(val,dist[node]);
                for(int j = 0 ; j <adj[node].size() ; j++ )
                {
                    if(dist[adj[node][j]] == INT_MAX){
                        q.push(adj[node][j]);
                    }
                }
            }
            val++;
        }
        for(int i = 0 ; i < N ; i++ )
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
        }
        };
        */