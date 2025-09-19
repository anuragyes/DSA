
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildAdj(TreeNode *root, unordered_map<int, vector<int>> &adj)
{
    if (!root)
        return;

    if (root->left)
    {
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
        buildAdj(root->left, adj);
    }

    if (root->right)
    {
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        buildAdj(root->right, adj);
    }
}

vector<int> Solution::distanceK(TreeNode *root, int B, int C)
{
    unordered_map<int, vector<int>> adj;
    buildAdj(root, adj);

    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(B);
    visited[B] = true;

    int dist = 0;
    vector<int> ans;

    while (!q.empty())
    {
        int size = q.size();

        if (dist == C)
        {
            while (size--)
            {
                ans.push_back(q.front());
                q.pop();
            }
            return ans;
        }

        while (size--)
        {
            int node = q.front();
            q.pop();

            for (auto nei : adj[node])
            {
                if (!visited[nei])
                {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        dist++;
    }

    return ans;
}
