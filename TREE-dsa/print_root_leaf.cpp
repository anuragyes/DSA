// #include <iostream>
// #include <vector>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
// };

// void solve(node *root, vector<vector<int>> &ans, vector<int> ds)
// {
//     if (root == NULL)
//         return;
//     ds.push_back(root->data);
//     if (root->left == NULL && root->right == NULL)
//     {
//         ans.push_back(ds);
//         return;
//     }
//     if (root->left)
//     {
//         solve(root->left, ans, ds);
//     }
//     if (root->right)
//     {
//         solve(root->right, ans, ds);
//     }
//     ds.pop_back();
// }
// vector<vector<int>> Paths(Node *root)
// {
//     // code here
//     vector<vector<int>> ans;
//     vector<int> ds;
//     solve(root, ans, ds);
//     return ans;
// }

// int main()
// {
//     // Create a sample binary tree
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     Print all root to leaf paths
//     printPaths(root);

//     Clean up memory

//     return 0;
// }
