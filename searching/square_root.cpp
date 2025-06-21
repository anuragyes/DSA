#include <iostream>
using namespace std;

int square(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int start = 1;
    int end = n;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
         int value = mid*mid;
        if (value <= n)
        {
           
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return  end;
}

int main()
{
    int arr = 3;
    cout << square(arr);
    return 0;
}