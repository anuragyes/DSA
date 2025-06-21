
/*class Solution {
public:


  steps :  find how many nodes are present

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL)
            return head; // edge case

        int cnt = 0; // count the nodes

        ListNode* ptr = head;
        while (ptr) {
            cnt++;
            ptr = ptr->next;
        }
        k = k % cnt;     // don't go to more rotation ;
        if (k == 0)      // in any case k == 0 no need for rotation;
            return head; // just return head;

        cnt = cnt - k;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (cnt--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode* tail = curr;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;
        head = curr;
        return curr;
    }
};*/