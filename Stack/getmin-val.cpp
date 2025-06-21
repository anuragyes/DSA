
#include <iostream>
#include <stack>
using namespace std;

int findMin(stack<int> &s)
{

    int topvalue = s.top(); // keep the top value  in side the stack
    s.pop();

    //    base case
    if (s.empty()) // now compare if the stack is empty  return the in side value
    {
        return topvalue;
    }
    int rest = findMin(s);      // recursive function
    return min(rest, topvalue); // and find the min value between rest and topvalue
}



int main()
{
    stack<int> myStack;

    myStack.push(3);
    myStack.push(45);
    myStack.push(24);
    myStack.push(40);

    int minValue = findMin(myStack);

    if (minValue != -1)
    {
        cout << "Minimum value in the stack: " << minValue << endl;
    }

    return 0;
}
