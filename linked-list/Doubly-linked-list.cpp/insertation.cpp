
#include <iostream>
using namespace std;

//  doubly linked list

class node
{
public:
    int data;
    node *next;
    node *previous;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->previous = NULL;
    };
};

node *insertatstart(node *head, int val)
{
    // node *first = new node(val);
    // first->next = head;
    // head = first;

    node *first = new node(val);
    //  if head IS NULL then return first node
    if (head == NULL)
    {
        return first;
    }
    //  tarverse  to the end of the doubly linked list
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    //  connect the new node to the last node in the list
    tail->next = first;
    first->previous = tail;

    return head;
};

void display(node *&head)
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
    node *first = new node(1000);
    node *head = first;
    insertatstart(head, 2000);

    insertatstart(head, 3000);
    insertatstart(head, 3400);

    display(head);
}