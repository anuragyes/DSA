#include <bits/stdc++.h>
#include <stack>
using namespace std;
#include <queue>
class Stack 
{

    int size;
    queue<int> q1;
    queue<int> q2;

public:
    Stack(int n)
    {
        size = 0;
    }

    void push(int val)
    {
        q2.push(val);
        // push all the element  from q2 to q1
        size++;
        while (!q1.empty())
        {
            int top = q1.front();
            q2.push(top);
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        // swap(q1,q2);
    }

    void pop()
    {
        q1.pop();
        size--;
    }

    int peek()
    {
        return q1.front();
    }
    int sizeOFStack()
    {
        return size;
    }
};

int main()
{
    Stack  s;
    st.push(3);
    st.push(13);
    st.push(32);
    st.push(33);
    return 0;
}