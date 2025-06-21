#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Solution class
class Solution {
  public:
    Node* prev = nullptr; // To keep track of the previous node in the DLL

    // Function to perform inorder traversal and build DLL
    void inorder(Node* root, Node*& head) {
        if (root == nullptr) return;

        // Recursively traverse the left subtree
        inorder(root->left, head);

        // Process current node
        if (prev == nullptr) {
            // This is the leftmost node, it will be the head of DLL
            head = root;
        } else {
            // Link the current node with the previous node
            prev->right = root;
            root->left = prev;
        }
        prev = root; // Update previous node

        // Recursively traverse the right subtree
        inorder(root->right, head);
    }

    // Function to convert binary tree to doubly linked list
    Node* bToDLL(Node* root) {
        if (root == nullptr) return nullptr;

        Node* head = nullptr; // Pointer to the head of the DLL
        inorder(root, head);  // Perform inorder traversal and link nodes

        return head; // Return the head of the DLL
    }
};

// Helper function to print the doubly linked list
void printList(Node* head) {
    Node* last = nullptr;
    while (head != nullptr) {
        cout << head->data << " ";
        last = head;
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Solution sol;
    Node* head = sol.bToDLL(root); // Convert binary tree to DLL

    // Print the created doubly linked list
    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}
