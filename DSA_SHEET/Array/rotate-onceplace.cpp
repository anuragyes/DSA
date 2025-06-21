#include <iostream>
using namespace std;

// /*Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 2,3,4,5,1
// Explanation:
// Since all the elements in array will be shifted
// toward left by one so ‘2’ will now become the
// first index and and ‘1’ which was present at
// first index will be shifted at last.*/

void solve(int arr[], int size)
{

    int temp[size];   //copy the element at temp variable

    for (int i = 1; i < size; i++)  // using loop  1 position to last position 
    {
        temp[i - 1] = arr[i];  
    }
    temp[size - 1] = arr[0]; // and we added first element of array at last potion of temp 

    for (int i = 0; i < size; i++)
    {
        cout << temp[i] << endl;
    }
}
int main()
{
    int n = 5;

    int arr[] = {1, 2, 3, 4, 5};
    solve(arr, n);
}
