#include <iostream>
using namespace std;



/*/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    // Function to find middle of linked list
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next; 
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // Function to merge two sorted linked lists
    Node* merge(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        while (l1 && l2) {
            if (l1->data < l2->data) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) curr->next = l1;
        else curr->next = l2;
        return dummy->next; 
    }
    // Merge sort function
    Node* segregate(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* mid = findMiddle(head);
        Node* rightHead = mid->next;
        mid->next = nullptr; 
        Node* left = segregate(head);
        Node* right = segregate(rightHead);
        return merge(left, right);
    }
};*/

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        Node *ptr = head;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt0 = 0;

        while (ptr != NULL)
        {
            if (ptr->data == 0)
                cnt0++;
            else if (ptr->data == 1)
                cnt1++;
            else
                cnt2++;

            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != NULL)
        {
            if (cnt0)
            {
                ptr->data = 0;
                cnt0--;
            }
            else if (cnt1)
            {
                ptr->data = 1;
                cnt1--;
            }
            else
            {
                ptr->data = 2;
                cnt2--;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
