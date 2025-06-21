#include <iostream>
#include <stack>
using namespace std;

// find the average to given element in stack

int average(stack<int> &mystack)
{
    //    base case
    if (mystack.empty())
    {
        return 0;
    }
    int firstelement = mystack.top();
    mystack.pop();

    int restelement = average(mystack);
    int count = firstelement + restelement;

    mystack.push(firstelement);
    return count;
}

int main()
{
    stack<int> myStack;

    myStack.push(3);
    myStack.push(45);
    myStack.push(24);
    myStack.push(40);

    int minValue = average(myStack);
    cout << minValue << endl;
}