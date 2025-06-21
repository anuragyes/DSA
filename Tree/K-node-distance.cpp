#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the graph with parent pointers
void buildGraph(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map)
{
    if (!root)
        return;

    if (root->left)
    {
        parent_map[root->left] = root;
        buildGraph(root->left, parent_map);
    }
    if (root->right)
    {
        parent_map[root->right] = root;
        buildGraph(root->right, parent_map);
    }
}

// Function to find all nodes at distance k from the target node
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_map;
    buildGraph(root, parent_map);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    vector<int> result;

    // Perform BFS to find nodes at distance k
    while (!q.empty())
    {
        int size = q.size();
        if (level == k)
        {
            while (!q.empty())
            {
                result.push_back(q.front()->val);
                q.pop();
            }
            break;
        }

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                visited[node->left] = true;
                q.push(node->left);
            }
            if (node->right && !visited[node->right])
            {
                visited[node->right] = true;
                q.push(node->right);
            }
            if (parent_map[node] && !visited[parent_map[node]])
            {
                visited[parent_map[node]] = true;
                q.push(parent_map[node]);
            }
        }
        level++;
    }

    return result;
}

int main()
{
    // Example: Build a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Define target node and k
    TreeNode *target = root->left; // Target is node 2
    int k = 2;

    // Get all nodes at distance k from target
    vector<int> result = distanceK(root, target, k);

    // Output the result
    cout << "Nodes at distance " << k << " from target " << target->val << " are: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
