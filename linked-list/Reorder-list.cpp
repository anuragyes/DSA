






// Input: head = [1,2,3,4]
// Output: [1,4,2,3]








/*class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Store the values in a vector
        vector<int> values;
        ListNode* ptr = head;
        while (ptr) {
            values.push_back(ptr->val);
            ptr = ptr->next;
        }

        // Step 2: Reorder the list using the vector
        ptr = head;
        int start = 0;
        int end = values.size() - 1;
        while (start <= end) {
            if (start == end) {
                ptr->val = values[start];
                break;
            } else {
                ptr->val = values[start];
                ptr = ptr->next;
                ptr->val = values[end];
                ptr = ptr->next;
            }
            start++;
            end--;
        }
    }
};*/