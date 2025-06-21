
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Kadane(int arr[], int size)
{

    int sum = 0;
    int maxi = arr[0];
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        //  if negative value comes  do sum = zero
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << Kadane(arr, size);
}