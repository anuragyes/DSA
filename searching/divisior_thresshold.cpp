#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int findmax(vector<int> &arr)
{
    int maxi = INT16_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int KOKO(vector<int> &arr)
{

    int start = 1;
    int end = INT16_MAX;
    int h = 8;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        cout << mid << endl;
    }
}
int main()
{
    vector<int> arr = {12, 45, 6, 77, 8};
    KOKO(arr);
    cout << findmax(arr);
}