#include <iostream>
using namespace std;

int main()
{

    int n = 121;
    int reversenumber = 0;
    int sum = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;

        reversenumber = (reversenumber * 10) + lastdigit;
        sum = sum + (lastdigit * lastdigit * lastdigit);
        n = n / 10;
    }

    int dup = n;
    if (dup == sum)
    {
        return true;
    }
    else
    {
        return false;
    }

    return 0;
}