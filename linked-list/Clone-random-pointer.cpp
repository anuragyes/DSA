


//  using unorder map optimal solution 
/*class Solution {
public:
    // Utility function to find the corresponding copy node from the original list
    //  optimal solution  using unorderedmap 
    Node* find(Node* head1, Node* head2, Node* x) {
    unordered_map<Node*, Node*> m;
    Node* temp1 = head1;
    Node* temp2 = head2;

    // Push all the address associations into the map
    while (temp1 != nullptr) {
        m[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Return the corresponding node for the random pointer of x
    return (x != nullptr) ? m[x] : nullptr;
}

// Function to copy the list with random pointers
Node* copyList(Node* head) {
    if (head == nullptr) return nullptr;

    // Step 1: Create a copy of the given list without random pointers
    Node* copyHead = new Node(0);  // Dummy node
    Node* copyTemp = copyHead;
    Node* temp = head;

    // Copy the list nodes
    while (temp != nullptr) {
        copyTemp->next = new Node(temp->data);
        temp = temp->next;
        copyTemp = copyTemp->next;
    }

    // Remove dummy node
    Node* actualCopyHead = copyHead->next;
    delete copyHead;

    // Step 2: Set up the random pointers in the copied list
    Node* originalTemp = head;
    Node* copyListTemp = actualCopyHead;

    while (originalTemp != nullptr) {
        copyListTemp->random = find(head, actualCopyHead, originalTemp->random);
        originalTemp = originalTemp->next;
        copyListTemp = copyListTemp->next;
    }

    return actualCopyHead;
}
   
   }
   */
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *find(Node *head1, Node *head2, Node *x)
    {
        //   edge case

        if (x == NULL)
            return NULL;

        Node *temp1 = head1;
        Node *temp2 = head2;
        while (temp1 != NULL)
        {
            if (temp1 == x)
                return temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        // Step 1: Create a copy of the given list without random pointers
        Node *copyHead = new Node(0); // Dummy node
        Node *copyTemp = copyHead;
        Node *temp = head;

        // Copy the list nodes
        while (temp != NULL)
        {
            copyTemp->next = new Node(temp->val);
            temp = temp->next;
            copyTemp = copyTemp->next;
        }

        // Remove dummy node
        copyTemp = copyHead;
        copyHead = copyHead->next;
        delete copyTemp;

        // Step 2: Set up the random pointers in the copied list
        Node *originalTemp = head;
        Node *copyListTemp = copyHead;

        while (originalTemp != NULL)
        {
            copyListTemp->random = find(head, copyHead, originalTemp->random);
            originalTemp = originalTemp->next;
            copyListTemp = copyListTemp->next;
        }
        //    return copyhead
        return copyHead;
    }
};