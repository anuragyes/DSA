/*class Solution
{
public:
    Node * removeDuplicates(struct Node *head)
    {
         
        Node* temp = head;
        while(temp != NULL && temp -> next != NULL)
        {
            Node* newnode = temp -> next;
            while(newnode != NULL && newnode ->data == temp -> data)
            {
                Node* duplicate = newnode;
                newnode = newnode -> next;
                delete duplicate;
            }
            temp -> next = newnode;
            if(newnode  != NULL)
            {
                newnode -> prev = temp;
            }
            temp = temp -> next;
        }
        return head;
    }
};*/