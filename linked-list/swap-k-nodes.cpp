
/*class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        
        // Find the first node to be swapped (kth node from beginning)
        ListNode* ptr1 = head;
        for (int i = 1; i < k; ++i) {
            ptr1 = ptr1->next;
        }
        
        // Find the second node to be swapped (kth node from end)
        ListNode* ptr2 = head;
        for (int i = 0; i < cnt - k; ++i) {
            ptr2 = ptr2->next;
        }
        
        // Swap the values
        swap(ptr1->val, ptr2->val);
        
        return head;
    }
};
*/