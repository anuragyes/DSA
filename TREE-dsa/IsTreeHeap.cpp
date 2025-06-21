#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:

    bool levelOrder(Node* tree) {
        if (tree == NULL) return true;

        queue<Node*> q;
        q.push(tree);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->left) {
                if (node->data < node->left->data) {
                    return false; // violates max-heap
                }
                q.push(node->left);
            }

            if (node->right) {
                if (node->data < node->right->data) {
                    return false; // violates max-heap
                }
                q.push(node->right);
            }
        }
        return true;
    }

    // Dummy version, you need to define your own complete tree check
    bool checkComplete(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool end = false;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left) {
                if (end) return false;
                q.push(current->left);
            } else {
                end = true;
            }

            if (current->right) {
                if (end) return false;
                q.push(current->right);
            } else {
                end = true;
            }
        }

        return true;
    }

    bool isHeap(Node* tree) {
        if (!tree) return true;
        bool complete = checkComplete(tree);
        bool heapProp = levelOrder(tree);
        return complete && heapProp;
    }
};






//  second approch 
class Solution {
    public:
    
        bool levelOrder(Node* tree) {
            if (tree == NULL) return true;
    
            queue<Node*> q;
            q.push(tree);
    
            while (!q.empty()) {
                Node* node = q.front();
                q.pop();
    
                if (node->left) {
                    if (node->data < node->left->data) {
                        return false; // violates max-heap
                    }
                    q.push(node->left);
                }
    
                if (node->right) {
                    if (node->data < node->right->data) {
                        return false; // violates max-heap
                    }
                    q.push(node->right);
                }
            }
            return true;
        }
    
        bool iscbt(Node *root, int index, int cnt) {
            if (root == NULL)
                return true;
    //    if nodelength cross the size of  the tree 
            if (index >= cnt)
                return false;
    
            bool left = iscbt(root->left, 2 * index + 1, cnt);
            bool right = iscbt(root->right, 2 * index + 2, cnt);
            return (left && right);
        }
    
        int cnt(Node* root) {
            if (root == NULL) return 0;
            return 1 + cnt(root->left) + cnt(root->right);
        }
    
        bool isHeap(Node* tree) {
            if (!tree) return true;
    
            bool heapProp = levelOrder(tree);
            int total = cnt(tree);
            int index = 0;
            bool complete = iscbt(tree, index, total);
    
            return complete && heapProp;
        }
    };