
#include <iostream>
#include <stack>
using namespace std;

//  insert an element at bottom

void insertAtBottom(stack<int> &mystack, int target)
{

    // base case
    if (mystack.empty())
    {
        mystack.push(target);
        return;
    }

    int num = mystack.top();
    mystack.pop();
    insertAtBottom(mystack, target);
    mystack.push(num);
};
int main()
{
    std::stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Element to be inserted at the bottom
    int elementToInsert = 444;

    // Call the insertAtBottom function
    insertAtBottom(myStack, elementToInsert);

    // Print the stack after insertion
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}