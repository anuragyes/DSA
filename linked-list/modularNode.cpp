/*int modularNode(Node* head, int k)
{
	 if (k <= 0 || head == NULL) return NULL; // Return NULL for invalid input
    
    int i = 1;
    Node* modular = NULL;
    
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        if (i % k == 0) {
            modular = temp; // Update modular node when i is a multiple of k
        }
        i++; // Increment i after checking
        
        // Note: You don't need an else block here; i is always incremented
    }
     if(modular==NULL)
         return -1;
         
     else
         
     return  modular->data;
     
    
};*/