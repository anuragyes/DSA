/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* ptr = head;

        // Step 1: Interleave cloned nodes into the list
        while (ptr) {
            Node* temp = new Node(ptr->val);
            temp->next = ptr->next;  // correct syntax (was missing ;)
            ptr->next = temp;
            ptr = temp->next;
        }

        // Step 2: Assign random pointers to the copied nodes
        ptr = head;
        while (ptr) {
            if (ptr->random) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        // Step 3: Separate the original and copied list
        ptr = head;
        Node* newHead = head->next;
        while (ptr) {
            Node* copy = ptr->next;
            ptr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            ptr = ptr->next;
        }

        return newHead;
    }
};
