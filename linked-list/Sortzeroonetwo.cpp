#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to segregate 0s, 1s and 2s
Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    // Dummy nodes for three lists
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);

    // Pointers to the current last nodes of the above lists
    Node* zero = zeroD;
    Node* one = oneD;
    Node* two = twoD;

    // Traverse the list and distribute the nodes
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Connect the three lists
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    // New head of the list
    Node* newHead = zeroD->next;

    // Free dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;

    return newHead;
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to insert node at end
void insert(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
}

// Example usage
int main() {
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 0);
    insert(head, 1);
    insert(head, 2);
    insert(head, 0);
    insert(head, 1);

    cout << "Original list: ";
    printList(head);

    head = segregate(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
