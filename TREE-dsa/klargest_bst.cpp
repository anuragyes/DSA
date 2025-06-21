
#include <iostream>
#include <vector>
#include <stack>
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

int kthLargest(node *root, int K)
{

    vector<int> ans;
    // inorder(root, K, ans);
}

int main()
{
    node *root = new node(2);
    node *left = new node(10);
    node *right = new node(10);
    return 0;
}

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

//      int ans ;
//     void find(Node* root,int &k){
//         if(root==NULL){
//             return ;
//         }
//         find(root->right,k);
//         k--;
//         if(k==0){
//             ans=root->data;
//             return ;
//         }
//         find(root->left,k);
//     }

//     int kthLargest(Node *root, int K)
//     {
//         find(root,K);
//         return ans;
//     }
// };