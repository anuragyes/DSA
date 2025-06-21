#include <iostream>



int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isPrime(number))
    {
        std::cout << number << " is a prime number.\n";
    }
    else
    {
        std::cout << number << " is not a prime number.\n";
    }

    return 0;
}
