

#include <bits/stdc++.h>
int maximumChocolates(vector<int> &arr, int k)
{

    periorty_queue<int> p;
    for (int i = 0; i < arr.size(); i++)

    p.push(arr[i]);
    long long maxeatchoclate = 0;
    while (k && (!p.empty()))
    {
        maxeatchoclate += p.top();
        if (p.top() / 2)
        {
            p.push(p.top() / 2);

            p.pop();
            k--;
        }
    }

    return maxeatchoclate % 1000000007;
}