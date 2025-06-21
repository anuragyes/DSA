

/*Find the Index of the First Occurrence in a String*/
/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

/*Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 */

#include <iostream>
#include <string>
using namespace std;

bool check(string str1, string str2)
{

    int i;
    i = str1.find(str2);
    return i;
}

int main()
{
    string hey = " leetcode";
    string match = "leeto";

    // string hey = "  sadbutsad";
    // string match = "sad";
    cout << check(hey, match);
    return 0;
}
