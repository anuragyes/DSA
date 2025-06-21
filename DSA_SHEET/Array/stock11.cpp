#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int stock(int prices[], int size)
{
    //   buy the stock

    int profit = 0;
    for (int i = 1; i < size; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}

int main()
{

    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = 7;
    cout << stock(arr, size);
    return 0;
}