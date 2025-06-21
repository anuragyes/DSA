#include <iostream>
using namespace std;

// bool canMakeSubsequence(string str1, string str2)
// {
//     int n = str1.size();
//     int m = str2.size();
//     int i = 0, j = 0;

//     while (i < n && j < m)
//     {
//         // Check if the current character in str1 can be transformed to
//         // match the character in str2
//         int diff = str2[j] - str1[i];
         
//         // If the difference is positive, or if it wraps around (cyclically)
//         if (diff == 0 || diff == 1 || diff == -25)
//         {
//             j++; // Move to the next character in str2
//         }
//         i++; // Move to the next character in str1
//     }

//     // If we've matched all characters in str2, return true
//     return j == m;
// }

int main()
{
    string str1 = "abc", str2 = "ad";
     string str = str1+str2;
      cout<<str;
    // cout << canMakeSubsequence(str1, str2);
    return 0;
}