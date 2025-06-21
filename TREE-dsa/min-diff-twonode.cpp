#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>
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

void mindiff(node *root, int &prev, int &ans)
{

    if (!root)
        return;

    mindiff(root->left, prev, ans);
    if (prev != INT_MIN)
    {
        ans = min(ans, root->data - prev);
    }
    prev = root->data;
    mindiff(root->right, prev, ans);
}
int mindistace(node *root)
{
    int prev = INT_MIN;
    int ans = INT_MAX;
    mindiff(root, prev, ans);
    return ans;
}
int main()
{

    node *root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(150);

    // cout << mindistace(root) << endl;
   

    return 0;
}