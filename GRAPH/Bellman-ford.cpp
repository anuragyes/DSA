// #include <iostream>
// using namespace std;

// int BellmanFord(vector<int> &adj[], vector<int> &ans)
// {
//     queue<pair<int, int>> q;
//     distance[S] = 0;
//     vector<int> distance(n + 1, INT_MAX);
//     q.push({0, S});

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int u = adj[j][0];
//             int v = adj[j][1];
//             int w = adj[j][2];

//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//             }
//         }
//     }

//     for (int j = 0; j < m; j++)
//     {
//         int u = adj[j][0];
//         int v = adj[j][1];
//         int w = adj[j][2];

//         if (dist[u] + w < dist[v])
//         {
//             dist[v] = dist[u] + w;
//             return -1;
//         }
//     }
//     return distance;
// };
