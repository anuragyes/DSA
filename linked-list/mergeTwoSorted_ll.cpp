/*
class Solution {
public:
ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        //    create a damenode
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        //  merge two sorted linked list
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        //    dont print damenode
        ans = ans->next ;return ans;
    }
    */
/*
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     // ListNode* res = merge(list1, list2);
     // return res;
     */

//   recursively optimal approch
/*
         if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

    }
};
*/