

#include <iostream>
#include <stack>
using namespace std;

// Function to delete a given value from the stack using recursion
void deleteValueFromStack(stack<int> &s, int valueToDelete)
{
    // Base case: stack is empty
    if (s.empty())
    {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively delete the value from the remaining stack
    deleteValueFromStack(s, valueToDelete);

    // If the current element is not the one to be deleted, push it back
    if (topElement != valueToDelete)
    {
        s.push(topElement);
    }
}

int main()
{
    stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(3); // Duplicate value

    // Display the original stack
    cout << "Original Stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    // Push the elements back onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(3); // Duplicate value

    // Value to be deleted
    int valueToDelete = 3;

    // Delete the specified value from the stack
    deleteValueFromStack(myStack, valueToDelete);

    cout << "\nStack after deleting " << valueToDelete << ": ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
