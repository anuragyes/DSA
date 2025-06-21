#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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

node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    node *left = lowestCommonAncestor(root->left, p, q);
    node *right = lowestCommonAncestor(root->right, p, q);

    // result
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    { // both left and right are not null, we found our result
        return root;
    }
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);

    return 0;
}
