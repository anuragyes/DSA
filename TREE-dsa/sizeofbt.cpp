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
//    this is the first method to find the size of tree
/*int sizeOfBinaryTree(node *root)
{
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }

    int left = sizeOfBinaryTree(root->left);
    int right = sizeOfBinaryTree(root->right);
    int ans = (left + right) + 1;
    return ans;
}*/

// this is the second method to find the size of tree  with the help of
void size(node *root, int &count)
{
    if (root == NULL)
        return;
    count++;
    size(root->left, count);
    size(root->right, count);
}
int getSize(node *root)
{

    int count = 0;
    size(root, count);
    return count;
}

int sumofallnode(node *root)
{
    int sum = 0;
    if (root == NULL)
    {
        return 0;
    }

    sum += root->data;
    int left = sumofallnode(root->left);
    int right = sumofallnode(root->right);
    return sum;
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
    // cout << sizeOfBinaryTree(root);
    int count = 0;
    // sizeOfBinaryTree(root, count);
    cout << sumofallnode(root);

    return 0;
}