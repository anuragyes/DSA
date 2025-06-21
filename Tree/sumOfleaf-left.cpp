#include <iostream>
#include <vector>
using namespace std;

//  sum of left leaf node

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


// int sumOfLeftLeaves(node *root)
// {
//     //  base case
//     if (root == NULL)
//         return 0;

//     int sum = 0;
//     if (root->left != NULL && root->left->left == NULL &&
//         root->left->right == NULL)
//     {
//         // If the left child of the root is a leaf node, add its value to
//         // the sum
//         sum += root->left->data;
//     }

//     // Recursively calculate the sum of left leaves in the left and right
//     // subtrees
//     sum += sumOfLeftLeaves(root->left);
//     sum += sumOfLeftLeaves(root->right);

//     return sum;
// }

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    // cout << sumOfLeftLeaves(root);


    return 0;
}