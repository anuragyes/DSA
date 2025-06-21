#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//   morrise traversal   is basically used for  optimaise the space complaxity of traversal
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getInOrderTraversal(node *root)
{
    vector<int> ans;

    while (root != NULL)
    {
        if (root->left == NULL)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            node *temp = root->left;

            // Find the rightmost node of the left subtree
            while (temp->right != NULL && temp->right != root)
            {
                temp = temp->right;
            }

            // Make a thread to the current node, if not already made
            if (temp->right == NULL)
            {
                temp->right = root;
                root = root->left;
            }
            else
            {
                // Thread already exists, so visit the node
                ans.push_back(root->data);
                temp->right = NULL; // Restore the tree structure
                root = root->right;
            }
        }
    }

    return ans;
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);
    vector<int> result = getInOrderTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
