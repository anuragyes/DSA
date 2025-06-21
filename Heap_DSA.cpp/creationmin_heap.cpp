#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  heap sort using min heap 

void creationminheap(int arr[], int size)
{
    priority_queue<int, vector<int>, greater<int>> pq;

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
    int arr[] = {23, 45, 65, 21, 22, 11};
    int size = 6;
    creationminheap(arr, size);
    return 0;
}