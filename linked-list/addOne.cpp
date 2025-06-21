  int helper(Node* ptr){
     
    //   base case imp 
      if(ptr==NULL) return 1;
      
      
     int   carry = helper(ptr->next);
      
       ptr->data = ptr->data + carry ;
       
        if(ptr->data < 10)
             return 0;
             
              ptr->data = 0 ;
              
               return 1;
        
      
  }

class Solution {
  public:
    Node* addOne(Node* head) {
        
          int carry = helper(head);
          
          if(carry == 1){
              Node* newroot =  new Node(1);
              newroot->next = head;
              return newroot;
          }
          return head;
    }
};