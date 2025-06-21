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
void insert(node *&head, int data)
{
    if (head == NULL)
    {
        node *n = new node(data);
    }

    node *first = new node(data);
    head = first;
}

node *removeKthnode(node *head, int K)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *fast = head;
    node *slow = head;

    for (int i = 0; i < K; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        return head->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    node *delnode = slow->next;
    slow->next = slow->next->next;
    delete delnode;
    return head;
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
int main()
{
    node *first = new node(1);
    node *head = first;
    insert(head, 100);
    insert(head, 1020);
    insert(head, 1100);
    insert(head, 1090);
    insert(head, 00);
    insert(head, 10);
    insert(head, 1);
    display(head);

    cout << " after deleting the node from the linked list";
    cout << removeKthnode(head, 2);
    display(head);

    return 0;
} 