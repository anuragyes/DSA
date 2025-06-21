#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

//  given =  n1 =60 and  n=270 find the element in the rrange of n1 AND  n2 in sorted way

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

void printInRange(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > n1 && root->data > n2)
    {
        return printInRange(root->left, n1, n2);
    }
    else if (root->data < n1 && root->data < n2)
    {
        return printInRange(root->right, n1, n2);
    }
    else
    {

        printInRange(root->left, n1, n2);
        cout << root->data << " ";
        printInRange(root->right, n1, n2);
    }
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);

    return 0;
}
