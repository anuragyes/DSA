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
    void find(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *node = q.front();
                q.pop();
                ans.push_back(node->data);

                if (node->left)
                {
                    q.push(root->left)
                }

                if (node->right)
                {
                    q.push(node->right);
                }

                if (ans.size() == 1)
                {
                    cout << ans[0] << endl;
                }
                else
                {
                    cout << ans[0] << " " << ans[ans.size() - 1] << endl;
                }
            }
        }
    }
};