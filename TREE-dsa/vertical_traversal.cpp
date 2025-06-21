#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    // Helper function to find the range of vertical positions
    void find(Node *root, int position, int &left, int &right)
    {
        if (!root)
            return;

        left = min(left, position);
        right = max(right, position);

        find(root->left, position - 1, left, right);
        find(root->right, position + 1, left, right);
    }

    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans; // Edge case: empty tree

        int left = 0, right = 0;
        find(root, 0, left, right);

        // Use arrays instead of vectors since we know the exact size
        vector<vector<int>> positive(right + 1);     // for positions >= 0
        vector<vector<int>> negative(abs(left) + 1); // for positions < 0

        queue<Node *> q;
        queue<int> index;
        q.push(root);
        index.push(0);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
            {
                positive[pos].push_back(temp->data);
            }
            else
            {
                negative[abs(pos)].push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right)
            {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        // Collect results from negative positions in reverse order
        for (int i = negative.size() - 1; i > 0; --i)
        {
            for (int j = 0; j < negative[i].size(); ++j)
            {
                ans.push_back(negative[i][j]);
            }
        }

        // Collect results from positive positions
        for (int i = 0; i < positive.size(); ++i)
        {
            for (int j = 0; j < positive[i].size(); ++j)
            {
                ans.push_back(positive[i][j]);
            }
        }

        return ans;
    }
};


//   opimal code by striver dsa sheet 

#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

// Assuming TreeNode is defined as:
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Fix: Typo "muliset" → "multiset"
    map<int, map<int, multiset<int>>> nodes;

    // Fix: Typo "paiur" → "pair"
    queue<pair<TreeNode*, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->val);

        if (node->left) todo.push({node->left, {x - 1, y + 1}});
        if (node->right) todo.push({node->right, {x + 1, y + 1}});
    }

    // Fix: Missing closing bracket and vector type for ans
    vector<vector<int>> ans;

    for (auto& p : nodes) {
        vector<int> col;
        for (auto& q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}
