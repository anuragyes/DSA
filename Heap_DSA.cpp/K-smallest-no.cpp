#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    cout << kthSmallest(arr, 0, 5, 4);
}