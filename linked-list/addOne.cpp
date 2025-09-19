

//  optimal code

class Solution
{
public:
  int helper(Node *temp)
  {

    // base case
    if (temp == NULL)
    {
      return 1;
    }

    int carry = helper(temp->next);
    temp->data += carry;

    //   backtracking process
    if (temp->data < 10)
      return 0;
    temp->data = 0;
    return 1;
  }

  Node *addOne(Node *head)
  {
    int carry = helper(head);

    if (carry == 1)
    {
      Node *newnode = new Node(1);
      newnode->next = head;
      return newnode;
    }

    return head;
  }
};

//  time compleccity in 2n and space is O(1) as we are not using any extra space  brute force approch
class Solution
{
public:
  Node *reverseList(Node *head)
  {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev; // new head
  }

  Node *addOne(Node *head)
  {
    // Step 1: Reverse the list
    head = reverseList(head);

    // Step 2: Add one
    Node *ptr = head;
    int carry = 1; // we need to add 1  as a carry

    while (ptr)
    {
      int number = ptr->data + carry;
      ptr->data = number % 10; // update digit
      carry = number / 10;     // carry for next

      if (carry == 0)
        break; // no more carry, stop early

      //  case 9999 +1 both condition are requried
      if (ptr->next == NULL && carry > 0)
      {
        ptr->next = new Node(carry);
        carry = 0;
        break;
      }
      ptr = ptr->next;
    }

    // Step 3: Reverse back to original order
    head = reverseList(head);
    return head;
  }
};

//   int helper(Node* ptr){

//     //   base case imp
//       if(ptr==NULL) return 1;

//      int   carry = helper(ptr->next);

//        ptr->data = ptr->data + carry ;

//         if(ptr->data < 10)
//              return 0;

//               ptr->data = 0 ;

//                return 1;

//   }

// class Solution {
//   public:
//     Node* addOne(Node* head) {

//           int carry = helper(head);

//           if(carry == 1){
//               Node* newroot =  new Node(1);
//               newroot->next = head;
//               return newroot;
//           }
//           return head;
//     }
// };