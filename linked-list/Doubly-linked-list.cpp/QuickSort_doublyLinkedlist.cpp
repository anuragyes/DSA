// C++ program to sort a doubly linked list
// using quicksort
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to swap the data of two nodes
void swap(Node *a, Node *b)
{

    // Swap the data in the nodes
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the list and find pivot
Node *partition(Node *low, Node *high)
{

    // Set pivot to the high node
    int pivot = high->data;

    // Pointer to place smaller elements
    Node *i = low->prev;

    // Traverse the list to rearrange nodes
    for (Node *j = low; j != high; j = j->next)
    {

        // If current node's data is less than or
        // equal to the pivot
        if (j->data <= pivot)
        {

            // Move i forward and swap with j
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }

    // Move i to the correct pivot position
    i = (i == nullptr) ? low : i->next;

    // Swap pivot with i's data
    swap(i, high);

    return i;
}

// Recursive function to apply quicksort
void quickSort(Node *low, Node *high)
{

    // Base case: if the list has one element or
    // invalid range
    if (low != nullptr && high != nullptr && low != high && low != high->next)
    {

        // Find the partition node (pivot)
        Node *pivot = partition(low, high);

        // Recursively sort the left half
        quickSort(low, pivot->prev);

        // Recursively sort the right half
        quickSort(pivot->next, high);
    }
}

// Function to get the last node of the list
Node *getLastNode(Node *head)
{

    // Traverse to the end of the list
    while (head != nullptr && head->next != nullptr)
    {
        head = head->next;
    }

    return head;
}

void printList(Node *node)
{
    Node *curr = node;
    while (curr != nullptr)
    {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

int main()
{

    // Create a hard-coded doubly linked list:
    // 5 <-> 3 <-> 4 <-> 1 <-> 2
    Node *head = new Node(5);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev =
        head->next->next;
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->prev =
        head->next->next->next;

    Node *last = getLastNode(head);
    quickSort(head, last);
    printList(head);

    return 0;
}