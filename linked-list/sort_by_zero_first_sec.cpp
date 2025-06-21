#include <iostream>
using namespace std;

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
