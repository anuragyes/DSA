#include <iostream>
using namespace std;

//  this is the first way to find  my answer  with the help of linear search
/*
int square(int n)
{
    int ans = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}
*/

//  this is the  second  way to find  my answer  with the help of  binary search

int square(int n)
{
    int ans = 1;
    int low = 1;
    int high = n;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}
int main()
{
    int n = 25;

    cout << square(n);
    return 0;
}