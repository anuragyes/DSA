#include <iostream>
#include <queue>
#include <vector>
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

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \
   20       30 */
int countLeaves(node *root)
{
    int count = 0;
    if (root == NULL)
        return 0;

    if (!root->left && !root->right)
        return 1;

    count = countLeaves(root->left) + countLeaves(root->right);
    return count;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    // root->left->left = new node(4);

    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // root->right->right->right = new node(10);

    cout << countLeaves(root);

    return 0;
}