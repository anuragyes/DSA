/*

int countNodesinLoop(struct Node *head)
{
     int count =1;
 Node* fast = head;
 Node* slow = head;
  while(fast!=NULL && fast->next!=NULL){
      slow = slow->next;
      fast = fast->next->next;
      
        if(fast==slow)
             break;
        }
        
  
        if(fast==NULL || fast->next==NULL){
             return 0;
        }
         slow = fast->next;
         while(fast!=slow){
             count++;
             slow = slow->next;
         }
          return count;
  
}*/