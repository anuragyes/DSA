#include <bits/stdc++.h>
using namespace std;

//  brute force approch
/*class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
    if (!head) return nullptr;

      priority_queue<int, vector<int>, std::greater<int>> minHeap;

        DLLNode* current = head;

        for (int i = 0; i <= k && current; ++i) {
            minHeap.push(current->data);
            current = current->next;
        }

        DLLNode* sortedHead = nullptr;
        DLLNode* sortedTail = nullptr;

        while (!minHeap.empty()) {
            int minVal = minHeap.top();
            minHeap.pop();

            DLLNode* newNode = new DLLNode(minVal);

            if (!sortedHead) {
                sortedHead = newNode;
                sortedTail = newNode;
            } else {
                sortedTail->next = newNode;
                newNode->prev = sortedTail;
                sortedTail = newNode;
            }

            if (current) {
                minHeap.push(current->data);
                current = current->next;
            }
        }

        return sortedHead;
    }
};
*/

// Node structure for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

// Function to sort a k-sorted doubly linked list
Node *sortKSortedDoublyLinkedList(Node *head, int k)
{
    if (!head)
        return head;

    // Insertion sort technique for a k-sorted doubly linked list
    Node *current = head->next;

    while (current)
    {
        Node *temp = current;
        // Compare temp with its previous k elements
        while (temp->prev && temp->data < temp->prev->data)
        {
            // Swap temp with temp->prev
            Node *prev = temp->prev;
            Node *prevPrev = prev->prev;
            Node *next = temp->next;

            // Adjust pointers for temp and prev
            if (prevPrev)
                prevPrev->next = temp;
            temp->prev = prevPrev;

            temp->next = prev;
            prev->prev = temp;

            prev->next = next;
            if (next)
                next->prev = prev;

            // Move head if needed
            if (!temp->prev)
                head = temp;
        }

        current = current->next;
    }

    return head;
}

// Utility function to insert a new node at the end of the doubly linked list
void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Utility function to print the doubly linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    Node *head = nullptr;
    insertNode(head, 3);
    insertNode(head, 6);
    insertNode(head, 2);
    insertNode(head, 12);
    insertNode(head, 56);
    insertNode(head, 8);

    int k = 2; // The list is k-sorted
    cout << "Original Doubly Linked List: ";
    printList(head);

    head = sortKSortedDoublyLinkedList(head, k);

    cout << "Sorted Doubly Linked List: ";
    printList(head);

    return 0;
}
