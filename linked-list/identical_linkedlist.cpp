/*//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    
    
      Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2=temp2->next;
        }
        return temp1 == nullptr && temp2 == nullptr;
    
    //  Node* ptr = head1;
    //   Node* temp = head2;
      
    //   int ptrcnt =0;
    //   int tempcnt =0;
      
    //   while(ptr!=NULL){
    //       if(ptr->data != temp->data ){
    //           return 0;
    //       }else{
    //           ptr = ptr->next;
    //           temp = temp->next;
    //       }
    //   }
       
    //   while(ptr!=NULL){
    //          ptr = ptr->next;
    //          ptrcnt++;
    //     }
    //      while(temp!=NULL){
    //          temp = temp->next;
    //          tempcnt++;
    //     }
      
    //   if(ptrcnt!=tempcnt) return 0;
      
    //     return 1;
       
        
}*/