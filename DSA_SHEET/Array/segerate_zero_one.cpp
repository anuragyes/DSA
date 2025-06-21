#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {0, 1, 1, 1, 0, 0, 1};
    int n = 7;
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[low]);
            low++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}