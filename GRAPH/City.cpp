class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            // Initialize distance matrix
            vector<vector<int>> dist(n, vector<int>(n, 1e9));
    
            for (int i = 0; i < n; i++) {
                dist[i][i] = 0;
            }
    
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                dist[u][v] = w;
                dist[v][u] = w;
            }
    
            // Floyd-Warshall algorithm
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
    
            int city = -1;
            int minReachable = n; // Maximum cities possible is n
    
            for (int i = 0; i < n; i++) {
                int reachable = 0;
                for (int j = 0; j < n; j++) {
                    if (i != j && dist[i][j] <= distanceThreshold) {
                        reachable++;
                    }
                }
                if (reachable <= minReachable) {
                    minReachable = reachable;
                    city = i; // In case of tie, choose the city with the greatest number
                }
            }
    
            return city;
        }
    };
    