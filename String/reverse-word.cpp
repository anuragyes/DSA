#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// string reverseWord(string input)
// {
//     string result;
//     int i = 0;
//     int n = input.length();
//     while (i < n)
//     {
//         while (i < n && input[i] == ' ')
//             i++;
//         if (i >= n)
//             break;
//         int j = i + 1;
//         while (j < n && input[i] != ' ')
//             j++;
//         string sub = input.substr(i, j - 1);
//         if (result.length() == 0)
//             result = sub;
//         else
//         {
//             result = sub + " " + result;
//             i = j + 1;
//         }
//         return result;
//     }
// }

// int main()
// {
//     string input = {"hey i am anurag pandey"};
//     cout << reverseWord(input);
// }