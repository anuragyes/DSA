#include <vector>
#include <queue>    
using namespace std;




class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        //  make adjlist   where we add 1 or 0 1 means to revere or change the
        //  path towards the node zero and 0 is already in right direction
        vector<vector<pair<int, int>>> adj(n);
        for (auto element : connections) {
            int u = element[0];
            int v = element[1];
            //  this  is very important face
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int change = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto [element, direction] : adj[node]) {
                if (!visited[element]) {
                    change += direction;
                    visited[element] = true;
                    q.push(element);
                }
            }
        }
        return change;
    }
};