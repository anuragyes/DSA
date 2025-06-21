




/*


#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteNode(ListNode* head, int x) {
    if (head == nullptr) {
        return nullptr; // Empty list
    }

    if (x == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    int count = 1;

    // Traverse to the xth node or to the end of the list
    while (curr != nullptr && count < x) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If x is greater than the length of the list
    if (curr == nullptr) {
        return head;
    }

    // Delete the xth node
    prev->next = curr->next;
    delete curr;

    return head;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    int x = 3; // Delete the 3rd node
    head = deleteNode(head, x);

    std::cout << "List after deleting node " << x << ": ";
    printList(head);

    // Clean up memory
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

*/