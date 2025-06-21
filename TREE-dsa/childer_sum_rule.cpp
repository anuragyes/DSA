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
bool isChildrenSum(node *root)
{
    // If the tree is empty or it's a leaf node, return true
    //  base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    int leftSum = 0, rightSum = 0;

    // Calculate the sum of left and right children
    if (root->left != NULL)
        leftSum = root->left->data;

    if (root->right != NULL)
        rightSum = root->right->data;

    // Check if the current node satisfies the children sum property
    if ((root->data == leftSum + rightSum) &&
        isChildrenSum(root->left) &&
        isChildrenSum(root->right))
        return true;
    else
        return false;
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(2);

    root->left->left = new node(1);
    root->left->right = new node(1);
    // Check if the binary tree satisfies the children sum property
    if (isChildrenSum(root))
        cout << "Binary tree satisfies children sum property." << endl;
    else
        cout << "Binary tree does not satisfy children sum property." << endl;

    return 0;
}
