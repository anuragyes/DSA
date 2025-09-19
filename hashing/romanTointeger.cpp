#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string romanToInt(string s)
    {
        int result = 0;
        int prevValue = 0;

        for (char c : s)
        {
            int value;
            switch (c)
            {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
            case 'X':
                value = 10;
                break;
            case 'L':
                value = 50;
                break;
            case 'C':
                value = 100;
                break;
            case 'D':
                value = 500;
                break;
            case 'M':
                value = 1000;
                break;
            default:
                value = 0; // Invalid character
            }

            if (value > prevValue)
            {
                result += value - 2 * prevValue; // Adjust for previous subtraction
            }
            else
            {
                result += value;
            }
            prevValue = value;
        }

        return result;
    }
};