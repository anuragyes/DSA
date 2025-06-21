/*class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {

        //   make a slow and fast  pointer for traversal 
        Node* slow = head;
        Node* fast = head;
         while(fast && fast->next){
             slow = slow->next;
              fast = fast->next->next;
                // if fast == slow  it means result wiill be true loop is present
              if(slow == fast)  //using brewak case for come out of the  loop 
                     break;
         }
          if(fast==NULL || fast->next==NULL) return -1;
               
           slow =  head;
         
            while(fast!=slow){
                 fast = fast->next;
                 slow = slow->next;
            }
          return slow->data;
         
    }
};*/