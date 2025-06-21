#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//  find the sum between  k1  and k2 smallest number
void sum(int arr[], int size, int k1, int k2)
{
    priority_queue<int> pq;
  
    //    smallest number
    for (int i = 0; i < k1; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k1; i < size; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int first = pq.top();

    for (int i = 0; i < k2; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k2; i < size; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int second = pq.top();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first && arr[i] < second)
        {
            sum = sum + arr[i];
        }
    }
    cout << sum;
}

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int size = 7;
    int k1 = 3;
    int k2 = 6;
    sum(arr, size, k1, k2);
    return 0;
}
