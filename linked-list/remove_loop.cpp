#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void detectAndRemoveLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *slow = head;
    Node *fast = head;

    // Move slow by one step and fast by two steps
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, there's a loop
        if (slow == fast)
            break;
    }

    // If there's no loop
    if (fast == NULL || fast->next == NULL)
        return;

    // Move slow to the beginning of the list and move both slow and fast one step at a time until they meet
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast)
    {
        slow = slow->next;
    }

    // Now, fast is at the last node of the loop. Break the loop by making its next null.
    slow->next = nullptr;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = head->next; // Creating a loop

    detectAndRemoveLoop(head);

    std::cout << "Linked list after removing loop: ";
    printList(head);

    return 0;
}
