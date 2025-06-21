#include <iostream>
#include <queue>
#include <stack>
using namespace std;


//  reverse the queue using stack 

void reverseQueue(queue<int> &q)
{
    //  create a stack
    stack<int> mystack;

    // Push elements from the queue to the stack
    while (!q.empty())

    {
        mystack.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (!mystack.empty())
    {
        q.push(mystack.top());
        mystack.pop();
    }
}

int main()
{
    queue<int> myqueue;

    // Enqueue elements to the queue
    for (int i = 1; i <= 5; ++i)
    {
        myqueue.push(i);
    }

    cout << "Original Queue: ";
    while (!myqueue.empty())
    {
        cout << myqueue.front() << " ";
        myqueue.pop();
    }

    // Enqueue elements to the queue again
    for (int i = 1; i <= 5; ++i)
    {
        myqueue.push(i);
    }

    // Reverse the queue
    reverseQueue(myqueue);

    cout << "\nReversed Queue: ";
    while (!myqueue.empty())
    {
        cout << myqueue.front() << " ";
        myqueue.pop();
    }

    return 0;
}
