#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
using namespace std;
//   using morise traversal in bst  optimal approch
/*
class Solution {
public:
    void fixed(TreeNode* root, TreeNode*& prev, TreeNode*& first,
               TreeNode*& second) {
        if (root == NULL)
            return;
        fixed(root->left, prev, first, second);
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        fixed(root->right, prev, first, second);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        fixed(root, prev, first, second);
        swap(first->val, second->val);
    }
};
*/

// Definition for a binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to insert a new node into BST
    Node *insert(Node *root, int data)
    {
        // If the tree is empty, return a new node
        if (root == nullptr)
        {
            return new Node(data);
        }

        // Otherwise, recur down the tree
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }

        // Return the (unchanged) node pointer
        return root;
    }

    // Function to perform inorder traversal of BST and collect nodes in sorted order
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    // Function to correct a BST
    Node *correctBST(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        vector<int> inorderNodes;
        inorder(root, inorderNodes);

        // Clear the original BST
        root = nullptr;

        // Reinsert the nodes in sorted order to create a correct BST
        for (int i = 0; i < inorderNodes.size(); ++i)
        {
            root = insert(root, inorderNodes[i]);
        }

        return root;
    }
};

// Helper function to print inorder traversal of BST
void printInorder(Node *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Solution sol;

    // Example BST with a mistake
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(10);

    cout << "Inorder traversal before correction: ";
    printInorder(root);
    cout << endl;

    // Correct the BST
    root = sol.correctBST(root);

    cout << "Inorder traversal after correction: ";
    printInorder(root);
    cout << endl;

    return 0;
}
