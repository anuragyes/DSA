/*You are required to complete this method*/
   #include <bits/stdc++.h>
using namespace std;        
// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// Function to check if all leaves are at the same level in a binary tree
// This function uses a level order traversal to check if all leaves are at the same level.




bool check(Node *root) {
        // Your code here
           if (!root) return true;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int leafLevel = -1;
        
        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (!node->left && !node->right) {
                if (leafLevel == -1)
                    leafLevel = level;
                else if (leafLevel != level)
                    return false;
            }
            
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }
        
        return true;
        
    }