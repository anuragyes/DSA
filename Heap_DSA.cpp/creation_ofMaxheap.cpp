#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//   using  priority_queue

void creationmaxheap(int arr[], int size)
{
    priority_queue<int> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    // int arr[] = {23, 45, 65, 21, 22, 11};
    int arr[] = {12, 5, 787, 1, 23};
    int size = 5;
    creationmaxheap(arr, size);
    return 0;
}