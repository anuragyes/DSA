#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    double x = 2.00000;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        ans = ans * x;
    }
    cout << ans << endl;
}