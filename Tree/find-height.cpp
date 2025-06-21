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
void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
};
void inorderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftside = height(root->left);
    int rightside = height(root->right);
    int ans = max(leftside, rightside) + 1;
    return ans;
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
    cout << "preorderTraversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "postorderTraversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "inorderTraversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "the height og given tree is :" << endl;
    cout << height(root);
    return 0;
}