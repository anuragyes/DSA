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

node *reverseNode(node *&head)
{
    node *ptr = head;
    stack<int> st;
    while (ptr != NULL)
    {
        st.push(ptr->data);
        ptr = ptr->next;
    }
    //  for pop the element on stack

    node *temp = head;
    while (temp != NULL)
    {
        int top = st.top();
        st.pop();
        temp = temp->next;
    }
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
    display(head);
    cout << " the reverse number will be " << endl;
    reverseNode(head);
    display(head);

    return 0;
}