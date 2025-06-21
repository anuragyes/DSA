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
        node *n = new node(2);
    }

    node *first = new node(data);
    head = first;
}
node *compute(node *head)
{
    node *ptr = head;
    node *temp = head->next;
    node *ans = new node(-1);
    while (temp != NULL)
    {
        if (ptr->data < temp->data)
        {
            ans->next = temp;
            ptr = ptr->next;
            temp = temp->next;
        }
    }
    ans = ans->next;
    return ans;
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

    insert(head, 10);
    insert(head, 20);
    insert(head, 2);
    insert(head, 34);
    insert(head, 20);
    cout << compute(head);
    display(head);

    return 0;
}