#include <bits/stdc++.h>
#include <queue>
using namespace std;

int solve(int arr[], int size, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }
    int maximum = 0;
    while (k-- && (!pq.empty()))
    {
        int topelement = pq.top();
        maximum += topelement;
        int given = topelement - 1;
         pq.pop();
        pq.push(given);
       
    }
    return maximum;
}

int main()
{
    int arr[4] = {6, 4, 2, 3};
    int size = 4;
    int k = 5;
    cout << solve(arr, size, k);
    return 0;
}