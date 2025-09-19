

#include <iostream>
using namespace std ;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


  
//     Node* swapKth(Node* head, int k) {
       /*
        //   brute force approcvh 
        Node* ptr = head;
        vector<int>ans;
        while(ptr){
            ans.push_back(ptr->data);
            ptr = ptr->next;
        }
        
        int n = ans.size();
        if (k > n) return head; // invalid k
        
        int start = 0;
        int end  = ans.size()-1;
        
        swap(ans[k-1], ans[n-k]);
           Node* temp = head;
           int i=0;
           
             while(temp){
                 temp->data = ans[i];
                 temp = temp->next;
                 i++;
             }
             
              return head;
              */
              
              
                // optimal approch 
                // }
                // }
                
                
                
                
class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Count length
        int n = 0;
        Node* curr = head;
        
        //   how many node present 
        while (curr) {
            n++;
            curr = curr->next;
        }

        if (k > n) return head;           // invalid
        if (2*k - 1 == n) return head;    // same node, no swap

        // Find kth node from start
        Node* x = head;
        Node* x_prev = NULL;
        for (int i = 1; i < k; i++) {
            x_prev = x;
            x = x->next;
        }

        // Find kth node from end
        Node* y = head;
        Node* y_prev = NULL;
        for (int i = 1; i < n-k+1; i++) {
            y_prev = y;
            y = y->next;
        }

        // If previous exists, link it
        if (x_prev) x_prev->next = y;
        if (y_prev) y_prev->next = x;

        // Swap next pointers
        Node* temp = x->next;
        x->next = y->next;
        y->next = temp;

        // If head changed
        if (k == 1) head = y;
        if (k == n) head = x;

        return head;
    }
};

     