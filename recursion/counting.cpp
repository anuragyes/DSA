#include <iostream>
using namespace std;
/*
void print(int n, int count)
{
    //  base case
    if (count == 11)
    {
        return;
    }
    cout << n * count << endl;

    print(n, count + 1);
}

*/



//  print  : 5,4,3,2,1 
void printreverse(int n)
{
    //  base case
    if (n == 0)
    {
        return;
    }
    cout << n << endl;

    printreverse(n - 1);
}

int main()
{
    int n = 5;
    int count = 5;
    // print(n, count);
    printreverse(n);
    return 0;
}
