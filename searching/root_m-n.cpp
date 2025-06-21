#include <iostream>
using namespace std;

int fun(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)

            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int square(int n, int m)
{

    int start = 1;
    int end = m;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int val = fun(mid, n, m);
        if (val == 1)

            return mid;

        else if (val == 0)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 2;
    int m = 4;
    cout << square(n, m);
    return 0;
}