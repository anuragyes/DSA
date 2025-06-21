#include <iostream>
#include <string>

int main()
{
    std::string str = "1"; // The string to be converted

    // Convert the string to an integer using std::stoi
    int num = std::stoi(str);

    // Output the result
    std::cout << "The integer value is: " << num << std::endl;

    int n = 6;

    for (int i = 1; i <= n; i++)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
