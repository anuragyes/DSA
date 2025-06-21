#include <iostream>
#include <unordered_map>
using namespace std;

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // If the current Roman numeral is smaller than the next one, subtract its value
        if (i < s.length() - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
        {
            result -= romanMap[s[i]];
        }
        else
        {
            // Otherwise, add its value
            result += romanMap[s[i]];
        }
    }

    return result;
}

int main()
{
    // Example usage
    string romanNumeral;
    cin >> romanNumeral;
    int integerValue = romanToInt(romanNumeral);

    cout << "Roman numeral: " << romanNumeral << endl;
    cout << "Integer value: " << integerValue << endl;

    return 0;
}
