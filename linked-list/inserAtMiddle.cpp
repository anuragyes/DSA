/*Node* insertInMiddle(Node* head, int x)
{
    
     if(head==nullptr ){
          return new Node(x);
     }
       Node* track = head;
      if(head->next == nullptr){
          track->next = new Node(x);
          return head;
      }
	
	    Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next!=nullptr &&fast->next->next!=nullptr){
            slow = slow->next;
            fast=fast->next->next;
        }
        Node* newnode = new Node(x);
        newnode->next = slow->next;
        slow->next = newnode;
        return head;
	
	   
}*/

 