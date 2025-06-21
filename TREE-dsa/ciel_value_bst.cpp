

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
int solve(node *root, int key, int &ans)
{

    if (root->data > key)
    {
        ans = root->data;
        solve(root->left, key, ans);
    }
    else
    {
        solve(root->right, key, ans);
    }
}
int findciel(node *root, int key)
{
    int ans = -1;
    if (root == NULL)
        return ans;
    solve(root, key, ans);
 return ans;
}

int main()
{

    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(11);

    root->left->left = new node(4);
    root->left->right = new node(7);
    cout << findciel(root, 2);

    return 0;
}