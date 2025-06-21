#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int stock(int arr[], int size)
{
    //   buy the stock

    int minimumSofar = arr[0];
    int maxprofit = 0;
    for (int i = 0; i < size; i++)
    {
        minimumSofar = min(minimumSofar, arr[i]);
        int profit = arr[i] - minimumSofar;
        maxprofit = max(maxprofit, profit);
    }
    return maxprofit;
}

int main()
{

    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = 7;
    cout << stock(arr, size);
    return 0;
}