/*
 there are few step to solve this question

*/

#include <iostream>
#include <stack>
using namespace std;

//  insert an element at bottom

void insertAtBottom(stack<int> &mystack, int element)
{
    if (mystack.empty()) // if stack is empty so insert the top element
    {
        mystack.push(element);
        return;
    }

    int top = mystack.top();
    mystack.pop();
    insertAtBottom(mystack, element);
    mystack.push(top);
}

void reverseStack(stack<int> &mystack)
{

    // base case
    if (mystack.empty()) // if given stack is empty so return
    {
        return;
    }

    int num = mystack.top(); // take a only top element and keep in side
    mystack.pop();

    reverseStack(mystack);        // call reverseStack function
    insertAtBottom(mystack, num); // call insertAtBottom function  and its work , we had taken top element at this function  insert that element at bottom of stack
};
int main()
{
    stack<int> myStack;

    // Push elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Original Stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    // Refill the stack for demonstration purposes
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Reverse the stack
    reverseStack(myStack);

    cout << "\nReversed Stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
