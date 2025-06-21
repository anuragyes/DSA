#include <iostream>
using namespace std;

//  blanced tree said to be when the left sub tree - right sub tree <=1 for every nodes

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

bool blanced(node *root)
{
    if (root == NULL)
        return 0;

    int leftside = height(root->left);
    if (leftside == -1)
        return false;
    int rightside = height(root->right);
    if (rightside == -1)
        return false;
    if (abs(leftside - rightside) <= 1)
        return true;
    // return max(leftside, rightside) + 1;
}
int main()
{
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);

    // root->left->left = new node(4);
    // root->left->right = new node(5);

    // root->right->left = new node(6);
    // root->right->right = new node(7);

    node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);

    root->right->left = new node(56);
    root->right->right = new node(7);
    cout << "Does the given tree is blanced ? " << height(root);
    cout << endl;

    cout << "given tree is blanced of not ?" << endl;
    if (blanced(root) == true)
    {
        cout << "given tree is blanced " << endl;
    }
    else
    {
        cout << "given tree is not blanced " << endl;
    }
    return 0;
}
