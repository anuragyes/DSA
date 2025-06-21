#include <iostream>
using namespace std;
/*
 TreeNode* traversal(TreeNode* cur, int key) {
        if (cur == NULL) {
            return NULL;
        }
        //  base case whwn we have only one node
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