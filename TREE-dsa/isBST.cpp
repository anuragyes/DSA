#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//  there are two ways to find out the given tree is bst ?
//   first approch inorder traverse ans check outcome ans is sorted if sorted return yes bst
//   second apprcoh  check for every nodes root data > left->side and root->data < right->side
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

void inorder(node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool bst(node *root)
{
    vector<int> ans;
    inorder(root, ans);
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])

            return 0;

        return 1;
    }
}

// second way to find bst ?

// bool isBST(node *root, int min, int max)
// {
//     if (root == NULL)
//         return;

//     if (min <= root->data && max > root->data)
//     {
//         bool left = isBST(root, min, root->data);
//         bool right = isBST(root, root->data, max);
//         return left && right;
//     }
// }

// bool bst(node *root)
// {
//     return isBST(root, INT_MIN, int INT_MAX);
// }

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);
    cout << bst(root);

    return 0;
}
