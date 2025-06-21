

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    int i = 0;
    while (i < n)
    {
        pq.push(arr[i]);
        if (pq.size() < k)
        {
            ans.push_back(-1);
        }
        else
        {
            while (pq.size() > k)
            {
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        i++;
    }
    return ans;
}