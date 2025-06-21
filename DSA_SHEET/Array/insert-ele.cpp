#include <iostream>
#include <map>
using namespace std;

/*Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if its present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.


Example 1:

Input:
N = 4
Arr = {1, 3, 5, 6}
k = 5
Output: 2
Explaination: Since 5 is found at index 2
as Arr[2] = 5, the output is 2.

Example 2:

Input:
N = 4
Arr = {1, 3, 5, 6}
k = 2
Output: 1
Explaination: Since 2 is not present in
the array but can be inserted at index 1
to make the array sorted.*/

// int check(int Arr[], int size, int k)
// {

//     for (int i = 0; i < size; i++)
//     {
//         if (Arr[i] == k)
//         {
//             return i;
//         }
//         else if (Arr[i] > k)
//         {
//             return i;
//         }
//     }
// }

// int main()
// {
//     int Arr[] = {1, 2, 4, 7};
//     int k = 6;
//     int size = 5;
//     // int k = 2;

//     cout << check(Arr, size, k);
// }

