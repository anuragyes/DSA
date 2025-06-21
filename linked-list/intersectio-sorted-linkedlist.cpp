#include <iostream>
#include <vector>
#include <algorithm>
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

node *arrayToLinkedList(vector<int> &arr)
{
    int size = arr.size();
    if (size == 0)
        return nullptr;

    // Create the head of the linked list
    node *head = new node(arr[0]);
    node *current = head;

    // Iterate through the array starting from index 1
    for (int i = 1; i < size; ++i)
    {
        // Create a new node for each element in the array
        node *newnode = new node(arr[i]);
        // Link the new node to the current node
        current->next = newnode;
        // Move the current pointer to the new node
        current = newnode;
    }

    return head;
}
node *findIntersection(node *head1, node *head2)
{
    stack<node *> st1;
    stack<node *> st2;
    vector<int> ans;

    node *ptr = head1;
    while (ptr != NULL)
    {

        st1.push(ptr);
        ptr = ptr->next;
    }
    ptr = head2;
    while (ptr != NULL)
    {

        st2.push(ptr);
        ptr = ptr->next;
    }
    while (!st1.empty() && !st2.empty())
    {
        if (st1.top()->data == st2.top()->data)
        {
            ans.push_back(st1.top()->data);
            st1.pop();
            st2.pop();
        }
        else if (st1.top()->data > st2.top()->data)
        {
            st1.pop();
        }
        else
        {
            st2.pop();
        }
    }
    reverse(ans.begin(), ans.end());

    return arrayToLinkedList(ans);
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
    insert(head, 0);
    insert(head, 110);
 

    // display(head);

    return 0;
}