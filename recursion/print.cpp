#include <iostream>
using namespace std;

/*Example:
Input: ‘n’  = 4

Output:
Coding Ninjas Coding Ninjas Coding Ninjas Coding Ninjas

Explanation: “Coding Ninjas” is printed 4 times. */

void print(int n, int count)
{  

    //  base case 
    if (n < count)
    {
        return;
    }

    cout << "anurag" << endl;

    print(n, count + 1);
}

int main()
{
    int n = 4;
    int count = 1;
    print(n, 1);
    return 0;
}

