class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count total nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: If we need to remove the first node
        if (n == count) {
            ListNode* newHead = head->next;
            delete head; // free memory
            return newHead;
        }

        // Step 3: Find the node just before the target node
        int steps = count - n - 1;
        temp = head;
        while (steps--) {
            temp = temp->next;
        }

        // Step 4: Remove the target node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
