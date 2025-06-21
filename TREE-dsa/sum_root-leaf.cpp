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
int solve(node *root, int &total, int sum)
{

    if (root == NULL)
        return 0;

    sum = sum * 10 + root->data;
    if (root->left == NULL && root->right == NULL)
    {
        total = total + sum;
        return;
    }
    if (root->left)
        solve(root->left, total, sum);
    if (root->right)
        solve(root->right, total, sum);
}
int sum(node *root)
{
    int total = 0;
    solve(root, total, 0);
    return total;
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);
    sum(root);

    return 0;
}
