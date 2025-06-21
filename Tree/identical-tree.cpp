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

bool same(node *root1, node *root2)
{
    //  case first
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    //  case second
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    //  case third
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    bool left = same(root1->left, root2->left); // condition 1 says   bool left goes left side of first tree and  also second tree
    bool right = same(root1->right, root2->right);
    bool value = root1->data == root2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    node *root1 = new node(1);

    root1->left = new node(2);
    root1->right = new node(3);

    node *root2 = new node(1);

    root2->left = new node(2);
    root2->right = new node(3);
    cout << same(root1, root2) << endl;

    return 0;
}