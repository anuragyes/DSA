
#include <iostream>
using namespace std;
#include <algorithm>

/*Given a number N, write a program to find a maximum number that can be formed using all of the digits of this number.
Note: The given number can be very large, so the input is taken as a String.



Example 1:

Input:
N = "38293367"
Output:
98763332
Explanation:
98763332 is the largest number that
can be formed by rearranging the
digits of N.*/

int main()
{
    long long int number = 896746557;
    // Convert number to a string
    string numberString = to_string(number);


    // Sort the string in descending order
    sort(numberString.begin(), numberString.end(), greater<char>());

    // Convert the sorted string back to a number
    long long int sortedNumber = stoll(numberString);

    // cout << "Original Number: " << number << endl;
    // cout << "Number in Descending Order: " << sortedNumber << std::endl;

    return 0;
}
