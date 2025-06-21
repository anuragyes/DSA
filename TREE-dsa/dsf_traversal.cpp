#include <iostream>
using namespace std;

//   DSF is a tech to traverse all the  node  or explore all  the nodes  present in the tree is called  dsf
//  there are three way to traverse every nodes of binary tree
// 1: inorder traverse :- traverse left , root , and last right

// 2: preorder traverse :- traverse  root ,left , and last right

// 3: postorder traverse :- traverse left , right  and last in root

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
void preorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void inorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder_traversal(root->left);
    cout << root->data << " ";
    postorder_traversal(root->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder_traversal(root);
    postorder_traversal(root);
    inorder_traversal(root);
    return 0;
}