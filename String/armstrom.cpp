#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include <iostream>

int main()
{
    int number = 153;

    int digit1 = number / 100;    // Extract the hundreds place digit
    int remaining = number % 100; // Get the remainder after dividing by 100
    int digit2 = remaining / 10;  // Extract the tens place digit
    int digit3 = remaining % 10;  // Extract the ones place digit

    int sum = digit1 * digit1 * digit1 +
              digit2 * digit2 * digit2 +
              digit3 * digit3 * digit3;

    return sum == number;

    return 0;
}
