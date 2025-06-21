// imp
class Solution
{
public:
    void DSF(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
                DSF(adj[node][i], adj, visited);
        }
    }
    int isCircle(vector<string> &arr)
    {
        vector<int> adj[26];
        vector<int> outdeg(26, 0);
        vector<int> indeg(26, 0);
        //  make adj list
        for (int i = 0; i < arr.size(); i++)
        {
            string temp = arr[i];
            int u = temp[0] - 'a';
            int v = temp[temp.size() - 1] - 'a';

            adj[u].push_back(v);

            outdeg[u]++;
            indeg[v]++;
        }
        vector<int> visited(26, 0);
        for (int i = 0; i < 26; i++)
        {
            if (outdeg[i] != indeg[i])
                return 0;
        }

        DSF(arr[0][0] - 'a', adj, visited);

        for (int i = 0; i < 26; i++)
        {
            if (indeg[i] && !visited[i])
            {
                return 0;
            }
        }

        return 1;
    }
};