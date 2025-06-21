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

node *search(node *root, int target)
{

    //  base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }

    //   root > target
    if (root->data > target)
    {
        return search(root->left, target);
    }
    //   root < target
    else
        return search(root->right, target);
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
    cout << search(root, 5) << endl;

    return 0;
}