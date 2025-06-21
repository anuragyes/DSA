#include <iostream>
using namespace std;

int  mountain(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[i] < arr[j] && arr[j] > arr[j + 1])
            {
                 return j;
            }
        }
    }
 
}
int main()
{
    int arr[] = {0, 10, 5, 2};
    int size = 3;
   cout<<  mountain(arr, size);
    return 0;
}