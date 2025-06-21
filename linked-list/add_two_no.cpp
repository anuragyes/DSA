

#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *reverse(node *curr, node *prev)
{
    if (curr == NULL)
        return prev;
    node *front = curr->next;
    curr->next = prev;
    return reverse(front, curr);
}
int addnum()

{
    node *first;
    node *second;
    first = reverse(first, NULL);
    second = reverse(second, NULL);

    node *curr1 = first;
    node *curr2 = second;
    node *head = new node(0);
    int carry = 0;
    node *tail = head;
    while (curr1 && curr2)
    {
        int sum = curr1->data + curr2->data + carry;
        tail->next = new node(sum % 10);
        tail = tail->next;
        curr1 = curr1->next;
        curr2 = curr2->next;
        carry = sum / 10;
    }
    while (curr1)
    {
        int sum = curr1->data + carry;
        tail->next = new node(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }
    while (curr2)
    {
        int sum = curr2->data + carry;
        tail->next = new node(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }
    while (carry)
    {
        tail->next = new node(carry % 10);
        carry /= 10;
    }
    head = reverse(head->next, NULL);
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
