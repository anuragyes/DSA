/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    // Count total nodes
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Check completeness using index
    bool isComplete(Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        
        return isComplete(root->left, 2*index+1, totalNodes) &&
               isComplete(root->right, 2*index+2, totalNodes);
    }
    
    // Check heap property
    bool isHeapUtil(Node* root) {
        if (!root) return true;
        
        // leaf node
        if (!root->left && !root->right) return true;
        
        // if right child is NULL, just check left
        if (!root->right) 
            return (root->data >= root->left->data) && isHeapUtil(root->left);
        
        // both children exist
        else {
            if (root->data >= root->left->data &&
                root->data >= root->right->data)
                return isHeapUtil(root->left) && isHeapUtil(root->right);
            else 
                return false;
        }
    }
    
    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        return isComplete(tree, 0, totalNodes) && isHeapUtil(tree);
    }
};
