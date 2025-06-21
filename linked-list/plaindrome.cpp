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

bool isPalindrome(node *&head)
{
    stack<int> st;
    node *ptr = head;
    while (ptr != NULL)
    {
        st.push(ptr->data);
        ptr = ptr->next;
    }

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
            return false;
        temp = temp->next;
        st.pop();
    }
    return true;
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

    return 0;
}