#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//  there are two ways to find out the given tree is bst ?
//   first approch inorder traverse ans check outcome ans  ansd make a variable count and when the value of counter equal to K just return
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

int inorder(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    int left = inorder(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return inorder(root->right, i, k);
}

int k(node *root, int k)
{

    int i = 0;
    int ans = inorder(root, i, k);
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    // root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << k(root, 2);

    return 0;
}
