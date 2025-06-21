#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //  find the middle node
    ListNode *findmiddle(ListNode *head)
    {

        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        //    create a damenode
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        //  merge two sorted linked list
        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        //    dont print damenode
        ans = ans->next;
        return ans;
    }
    ListNode *sortList(ListNode *head)
    {
        //  base case
        if (head == NULL || head->next == NULL)
            return head;
        //    find middle node
        ListNode *mid = findmiddle(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        //  sort two list
        left = sortList(left);
        right = sortList(right);

        ListNode *res = merge(left, right);
        return res;
    }
};