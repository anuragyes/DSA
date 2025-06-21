#include <iostream>
using namespace std;

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

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    //   case first
    if (left != NULL && right != NULL)
    {
        return root;
    }
    //   case second
    if (left == NULL && right == NULL)
    {
        return root;
    }
    //   case third
    if (!left)
    {
        return lca(root->left, n1, n2);
    }
    else
    {
        return lca(root->right, n1, n2);
    }
}

int convertBTBST(node *root)
{
    if (root == NULL)
        return;
    int ptr = root->data;
    if (ptr >= root->left)
}

int main()
{
    return 0;
}