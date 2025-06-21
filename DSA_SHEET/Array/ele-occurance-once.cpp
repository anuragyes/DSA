

#include <iostream>
using namespace std;
/*
Find the number that appears once, and the other numbers twice
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

*/
/*

int onces(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        int cnt = 0;

        for (int j = 0; j < size; j++)
        {
            if (arr[j] == num)
            {
                cnt++;
            }
        }
        if (cnt == 1)
            return num;
    }
    return -1;
}



int main()
{
    int arr[] = { 12, 12, 14, 90, 14, 14, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << onces(arr, size);
}
*/

// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}


// Driver Method
int main()
{
    int arr[] = {12, 12, 14, 90, 14 ,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The odd occurring element is " << findOdd(arr, n);
    return 0;
}

// This code is contributed by shivanisinghss2110
