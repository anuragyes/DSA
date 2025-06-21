#include <iostream>
using namespace std;

int main()
{

    int n = 12345;
    int reversenumber = 0;

    while (n > 0)
    {
        int lastdigit = n % 10;
        n = n / 10;
        reversenumber = (reversenumber * 10) + lastdigit;
    }
    cout << reversenumber << endl;
    return 0;
}