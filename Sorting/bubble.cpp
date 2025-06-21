
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{

    int counter = 1;
       
  
    while (counter < n) // n   = size of array
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }

    // for (int i = 0; i < n ; i++)
    // {
    //     cout << arr[i] << endl;
    // }
}

int main()
{
    int arr[] = {1, 67, 3, 89, 32, 90};
    int size = 6;
    bubbleSort(arr, size);
    return 0;        
}