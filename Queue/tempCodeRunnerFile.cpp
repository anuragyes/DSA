
{
    stack<int> s;

    // Push elements from the queue to the stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
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
        myq