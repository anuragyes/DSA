#include <iostream>
#include <queue>
using namespace std;
/*
class solution
{
public:
    // Function to insert heap.
    priority_queue<int> leftmaxheap; //,vectoe<int>greatermax heap
    priority_queue<int, vector<int>, greater<int>> rightminheap;

    void insertHeap(int &x)
    {
        if (leftmaxheap.empty())
        {
            leftmaxheap.push(x);
            return;
        }
        if (x > leftmaxheap.top())
        {
            rightminheap.push(x);
        }
        else
        {
            leftmaxheap.push(x);
        }
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        //  rightminheap size should not be greater than leftmaxheap size
        if (rightminheap.size() > leftmaxheap.size())
        {
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }
        else
        {
            // difference between the element of min heap and max heap should not be greater tan 2
            if (rightminheap.size() < leftmaxheap.size() - 1)
            {
                rightminheap.push(leftmaxheap.top());
                leftmaxheap.pop();
            }
        }
    }

    // Function to return Median.
    double getMedian()
    {
        //  leftmaxheap > rightminheap
        if (leftmaxheap.size() > rightminheap.size())
        {
            return leftmaxheap.top();
        }
        else
        {
            double answer = leftmaxheap.top() + rightminheap.top();
            answer /= 2;
            return answer;
        }
    }
};
*/