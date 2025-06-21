#include <iostream>
#include <vector>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left, * right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper function to find the path from root to a given node
bool findPath(Node* root, int n, vector<int>& path) {
    // Base case: if the tree is empty, return false
    if (root == nullptr) {
        return false;
    }
    
    // Add the current node to the path
    path.push_back(root->data);
    
    // If the current node matches the target, return true
    if (root->data == n) {
        return true;
    }
    
    // Otherwise, check the left or right subtree
    if ((root->left && findPath(root->left, n, path)) || 
        (root->right && findPath(root->right, n, path))) {
        return true;
    }
    
    // If the node is not found in either subtree, remove the current node from the path and return false
    path.pop_back();
    return false;
}

// Function to print the path from root to the node
void printPath(Node* root, int n) {
    vector<int> path;
     vector<int>path2;
    if (findPath(root, n, path)) {
        cout << "Path from root to " << n << ": ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Node not found in the tree!" << endl;
    }


    if (findPath(root, n, path2)) {
        cout << "Path from root to " << n << ": ";
        for (int i = 0; i < path2.size(); i++) {
            cout << path2[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Node not found in the tree!" << endl;
    }
}

// Main function
int main() {
    // Construct the binary tree
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    
    // Find and print the path from root to node 6
    printPath(root, 6);
    printPath(root, 4);
    
    return 0;
}
