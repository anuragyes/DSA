#include <bits/stdc++.h>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k) {
    // Adjacency list
    vector<vector<int>> adj(k);
    vector<int> indegree(k, 0);
    
    int n = dictionary.size();

    // Build graph from adjacent words
    for (int i = 0; i < n - 1; i++) {
        string word1 = dictionary[i];
        string word2 = dictionary[i + 1];
        
        int len = min(word1.size(), word2.size());
        for (int j = 0; j < len; j++) {
            if (word1[j] != word2[j]) {
                int u = word1[j] - 'a';
                int v = word2[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
                break; // only first mismatch matters
            }
        }
    }

    // Kahn's algorithm for topological sort
    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    string ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans += (char)(node + 'a');

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Optional: check for cycle (if not all letters are in ans)
    if (ans.size() < k)
        return ""; // Cycle exists, invalid dictionary

    return ans;
}
