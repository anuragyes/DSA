#include <iostream>
#include <stack>
using namespace std;
/* Largest Odd Number in String   xample 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".*/

// int odd(string str)
// {
//     stack<char> s;
//     int count = 0;

//     for (int i = 0; i < str.size(); i++)
//     {
//         char s = str[i];

//     }
//     int num = s.top();
//     s.pop();
//     if (num % 2 != 0 && count < s.top())
//     {
//         count = s.top();
//     }

//     odd(str);
//     s.push(num);
// }

void odd(string str)
{
    int count = -1;

    for (int i = 0; i < str.size(); i++)
    {
        char s = str[i];

        if (s % 2 != 0 && count < s)
        {
            count = s;
        }
    }

    cout << "Maximum odd character: " << count << std::endl;

    // cout << "No odd character found." << endl;
}


 int main(){
     string str = "45";
   odd( str);
     return 0;
 }