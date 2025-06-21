#include <iostream>
using namespace std;

void fun(int count)
{
    // base case
    if (count == 4)
    {
        return;
    }
    cout << 1 << endl;
    fun(count + 1);
}

int main()
{
    fun(0); // Initialize count to 0
    return 0;
}
