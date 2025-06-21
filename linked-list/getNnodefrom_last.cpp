

/*

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        //  if(n==1){
        //      return head->data;
        //  }
          Node* ptr = head;
         int  count = 0;
         while(ptr->next!=NULL){
          count++;
              ptr = ptr->next;
                  
         }
          n  = count-n+1;
          if(n<0) return -1; //edge case 
        Node* temp = head;
          while(n!=0){
                temp = temp->next;
                n--;
          }
          return temp->data;
           
    }
};
*/