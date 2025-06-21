#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int size;
    int top;

public:
    stack()
    {
        size = 10;
        top = -1;
        arr = new int[size];
    }

    void push(int data)
    {
        top++;
        arr[top] = data;
    }
    int peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    };

    int length()
    {
        return top + 1;
    }
};

int main()
{
    stack st;
    st.push(20);
    st.push(30);
    st.push(201);
    st.push(302);

    st.pop();
    cout << "Size of stack before deleting any element " << st.length() << endl;
    cout << st.peek();
}