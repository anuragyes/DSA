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

bool sum(node *root)
{
    int currentroot = root->data;

    if (root == NULL)
    {
        return true;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    int ansOfSum = leftsum + rightsum;

    if (ansOfSum == currentroot)
    {
        return true;
    }
    else
    {
        false;
    }
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    cout << sum(root) << endl;

    return 0;
}