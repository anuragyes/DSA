#include <iostream>
using namespace std;
//   you have given a number x = 2 and n = 10 find the power of 10^4= 10000;
// using recursion
int  power(double x, double n)
{
    // base case
    int ans = 1;
    int nn = n;
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }

    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}

int main()
{
    int result = power(3, 4);
    cout << result << endl;
    return 0;
}