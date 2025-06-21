#include <iostream>
using namespace std;

//  print the sum of 5+4+3+2+1 = 15
int factorial(int n)
{

    //  base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n = 5;

    cout << factorial(n);
    return 0;
}
