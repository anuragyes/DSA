#include <iostream>
using namespace std;

int storewater(int arr[], int size)
{

    int index = 0;
    int maxheight = arr[0]; // assume arr[0] is the max value (height)
    int leftmax = 0;
    int rightmax = 0;
    int water = 0;
    //  firstly find the max  height (arr) which is gievn
    for (int i = 1; i < size; i++)
    {
        if (maxheight < arr[i])
        {
            maxheight = arr[i];
            index = i;
        }
    }

    //  solve left part
    for (int i = 0; i < index; i++)
    {

        if (leftmax > arr[i])
        {
            water += (leftmax - arr[i]);
        }
        else
            leftmax = arr[i];
    }
    for (int i = size - 1; i > index; i--)
    {
        if (rightmax > arr[i])
        {
            water += (rightmax - arr[i]);
        }
        else
            rightmax = arr[i];
    }
    return water;
}
int main()
{
    int height[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = 12;
    cout << storewater(height, size);
    return 0;
}