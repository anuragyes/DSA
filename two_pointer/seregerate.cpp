#include <iostream>
using namespace std;

//  brute force approch 
void shift(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

//  optimal approch 
// void shift(int arr[], int size)
// {
//     int start = 0;
//     int end = size - 1;
//     while (start <= end)
//     {
//         if (arr[start] == 0)
//             start++;
//         else
//         {
//             if (arr[end] == 0)
//             {
//                 swap(arr[start], arr[end]);
//                 start++, end--;
//             }
//             else
//             {
//                 end--;
//             }
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << endl;
//     }
// }

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1};
    int size = 6;
    shift(arr, size);
    return 0;
}