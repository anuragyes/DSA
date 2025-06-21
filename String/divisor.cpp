
#include <bits/stdc++.h>
#include <string>
using namespace std;
/*
given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

*/
string deletedigit(string str1, string str2)
{
    return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
}

int main()
{
    string str1 = "ABCABC";
    string str2 = "ABC";
    deletedigit(str1, str2);
    return 0;
}