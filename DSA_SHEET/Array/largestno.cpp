#include <iostream>
using namespace std;

void findmaxmin(int arr[], int size)
{

    int max = arr[0];
    

    for (int i = 0; i < size; ++i) {
       
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout<<"this is max value: " << max << endl;
}

int main()
{
    int arr[6] = {12, 34, 43, 55, 68, 9};
    findmaxmin(arr, 6);
    return 0;
}