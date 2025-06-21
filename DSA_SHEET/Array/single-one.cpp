#include <iostream>
using namespace std;
//  single one
/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.*/

int main()
{
    int size = 3;
    int arr[] = {1, 2, 1};

    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res ^ arr[i];
    }

    cout << res << endl;
    return 0;
}