
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
void sortednum(stack<int> &mystack, int element)
{
    //  base case
    if (mystack.empty() || (!mystack.empty() && mystack.top() < element))
    {
        mystack.push(element);
        return;
    }
    int num = mystack.top();
    mystack.pop();
    sortednum(mystack, element);
    mystack.push(num);
}

void sorted(stack<int> &mystack)
{

    // base case
    if (mystack.empty()) // if given stack is empty so return
    {
        return;
    }
    int num = mystack.top();
    mystack.pop();
    sorted(mystack);

    sortednum(mystack, num);
};
*/

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();

        // while temporary stack is not empty and top
        // of stack is lesser than temp
        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in temporary of stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main()
{
    stack<int> myStack;

    // Push elements into the stack
    myStack.push(111);
    myStack.push(232);
    myStack.push(133);
    myStack.push(49);
    myStack.push(518);

    //  sorting the stack
    // sorted(myStack);
   sortStack(myStack);

    cout << "sort Stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
