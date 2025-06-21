
// Delete nodes having greater value on right

//  question 
/*
Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.*/


/*class Solution
{
    public:
    Node *compute(Node *head)
    {
       
        if(head->next==NULL)return head;
        vector<int> v;
        Node* a = head;
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        
        vector<int> st;
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        return ans;
        // your code goes here
      
    }
    
};
*/