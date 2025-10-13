#include <iostream>
using namespace std;
/*
 TreeNode* traversal(TreeNode* cur, int key) {
        if (cur == NULL) {
            return NULL;
        }
        //  base case whwn we have only one node  :  case first
        if (cur->val == key && !cur->left && !cur->right) {
            return NULL;
        } else if (cur->val == key && cur->left && !cur->right) {
            return cur->left;
        } else if (cur->val == key && !cur->left && cur->right) {
            return cur->right;
        } else if (cur->val == key && cur->left && cur->right) {
            TreeNode* node = cur->right;
            while(node->left != NULL) {
                node = node->left;
            }
            node->left = cur->left;
            return cur->right;
        }

        cur->left = traversal(cur->left, key);
        cur->right = traversal(cur->right, key);
        return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traversal(root, key);
    }
    */

node *inorderSuccesor(node *root)
{
    node *current = root;

    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *deletenode(node *root, int key)
{

    //    search key for deletetion
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        //  finally we are at key point
        //  case 1
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        //  case 2
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        //    case third
        node *temp = inorderSuccesor(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}