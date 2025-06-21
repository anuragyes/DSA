#include <iostream>
#include <queue>
using namespace std;
int kthlaregst(int arr[], int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < size; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

/*

//  first way to find the  k th largest number in heap

void Klargest(int arr[], int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]); // push all the element into pq
    }
    while (k--)
    {
        int element = pq.top();
        pq.pop();
    }
    int ans = pq.top();
    cout << ans << endl;
}
*/

int main()
{
    int arr[] = {20, 10, 60, 30, 50, 40, 2, 34, 6, 7, 88};
    int size = 11;
    // Klargest(arr, size, 4);
    cout << kthlaregst(arr, size, 3);
    return 0;
}