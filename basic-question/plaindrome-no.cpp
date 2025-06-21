#include <iostream>
using namespace std;

int main()
{

    int n = 121;
    int reversenumber = 0;

    while (n > 0)
    {
        int lastdigit = n % 10;

        reversenumber = (reversenumber * 10) + lastdigit;
        n = n / 10;
    }

    int dup = n;
    if (dup == reversenumber)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}