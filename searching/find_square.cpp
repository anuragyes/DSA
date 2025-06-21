#include <iostream>
using namespace std;
//   find the  square root ?
//  given number is 7  answer will be  2  floor value is taken

int square(int n)
{
    int start = 1;
    int end = n;
    int ans = 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cout << square(65);
    return 0;
}