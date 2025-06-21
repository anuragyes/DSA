

#include <iostream>
using namespace std;




void shiftingZeroesAtlast(int arr[], int size)
{
    int counter = 1;
    while (counter < size)
    {
        for (int i = 0; i < size - counter; i++)
        {

            if (arr[i] < arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {1,0,5,0,9,0,3,2,0,7,0};
    int size = sizeof(arr) / sizeof(arr[0]);
   shiftingZeroesAtlast(arr, size);
    return 0;
}