#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void product(int arr[], int size)
{
    int pro = 1;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        pro *= arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        int num = pro / arr[i];
        ans.push_back(num);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{

    int arr[] = {-1, 1, 0, -3, 3};
    int size = 5;
    product(arr, size);
    return 0;
}