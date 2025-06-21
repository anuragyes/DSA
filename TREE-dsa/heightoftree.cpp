#include <iostream>
using namespace std;
//  find max height

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

int height(node *root)
{
    if (root == NULL)

        return 0;

    int leftside = height(root->left);

    int rightside = height(root->right);

    return 1 + max(leftside, rightside);
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
    cout << "the maximum height of the given tree is " << height(root);

    return 0;
}