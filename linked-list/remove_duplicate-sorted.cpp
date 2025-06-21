#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};
// utility function to insert node at the end of the linked list
void insertNode(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

void remove(node *head)
{
    vector<int> ans;

    stack<int> st;
    node *ptr = head;

    while (ptr->next != NULL)
    {
        if (st.empty())
            st.push(ptr->num);
        ptr = ptr->next;

        if (st.top() == ptr->num)
        {
            st.pop();
            st.push(ptr->num);
            ptr = ptr->next;
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

// utility function to print linked list created
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main()
{
    // creation of both lists
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 4);
    remove(head);
}