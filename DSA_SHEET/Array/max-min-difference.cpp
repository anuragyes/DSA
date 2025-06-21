#include <iostream>
using namespace std;

int main()
{
    int arr[] = {-2, 1, -4, 5, 3};
    int size = 5;
    int result = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    result = max +  min;
    cout << " the maximum number is : " << max << " the min number is :" << min << " and  addition of max , min is : " << result << endl;

    return 0;
}