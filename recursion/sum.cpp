#include <iostream>
using namespace std;

//  print the sum of 5+4+3+2+1 = 15
void print(int n)
{

    //  base case
    if (n == 0)
    {
        return;
    }

    int sum = n * (n + 1) / 2;

    print(n - 1);

    cout << sum << endl;
}

int main()
{
    int n = 5;

    print(n);
    return 0;
}
