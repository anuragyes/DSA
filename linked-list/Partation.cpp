
   debug the code below
#include <iostream> 
using namespace std;
#include <vector>
#include <queue>
class Node
{
};

Node *partation(Node *node)
{

    if (!node || !node->next)
    {
        return NULL;
    }

    Node *smaller = new Node(-1);
    Node *larger = new Node(-1);

    Node *small = smaller;
    Node *large = larger;

    Node *ptr = head;

    while (ptr)
    {
        if (ptr->val > x)
        {
            large->next = ptr;
            large = larger->next;
        }
        else
        {

            small->next = ptr;
            small = small->next;
        }

        ptr = ptr->next;
    }


      Node* temp = smaller->next;
    larger->next = NULL; // end the larger list
    small->next = larger->next; // connect smaller and larger lists
    return temp; // return the head of the smaller list
}

int main()
{
    return 0;
}
