
/*
class Solution {
    public:
    Node* deleteK(Node *head,int K){
         if(K==1) return NULL;
    
      Node* prev = NULL;
      Node* curr = head;
      int count = 1;
       
       while(curr){
            if(count==K){
           prev->next = curr->next;
           delete curr;
           curr= prev->next;
            count = 1;
            }else{
                prev = curr;
                curr = curr->next;
                count++;
            }
            
       }
       
       
         return head;
       
    }
};
*/
