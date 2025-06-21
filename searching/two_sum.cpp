#include <iostream>
#include <vector>
using namespace std;

void TwoSum(int arr[], int size, int k)
{
    vector<int> ans;
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

        int sum = arr[start] + arr[end];
        if (sum == k)
        {
            cout << " first  array is " << arr[start] << " "
                 << " second   array is " << arr[end];
        
        }
        else if (sum < k)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    
}

int main()
{
    int arr[] = {2, 3, 5, 7, 9};
    int k = 12;
    int size = 5;
    TwoSum(arr, size, k);
    return 0;
}
