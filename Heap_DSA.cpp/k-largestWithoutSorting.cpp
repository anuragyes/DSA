#include <bits/stdc++.h>
using namespace std;

void kth_Largest_MaxHeap(vector<int> &arr, int k)
{

    priority_queue<int> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Largest element " << pq.top() << "\n";
}

void kth_Smallest_MinHeap(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Smallest element " << pq.top() << "\n";
}
int main()
{

    vector<int> arr = {3,2,1,5,6,4};

    kth_Largest_MaxHeap(arr, 2);
    kth_Smallest_MinHeap(arr, 3);

    return 0;
}