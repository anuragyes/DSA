// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// int remove(string input)
// {
//     int index = 0;
//     string ans = " ";
//     for (int i = 0; i < input.size() - 1; i++)
//     {
//         for (int j = i + 1; j < input.size(); j++)
//         {
//             if (input[i] == input[j])
//             {
//                 continue;
//             }
//             else
//             {
//                 ans = input[j];
//             }
//         }
//     }
//     return ans;
// }

// int main()
// {

//     string input;
//     cout << "enter the brackets" << endl;
//     cin >> input;
//     remove(input);

//     return 0;
// }

#include <iostream>
using namespace std;
string removeOuterParentheses(const string &input)
{
    string result;
    int count = 0;

    for (char ch : input)
    {
        if (ch == '(' && count++ > 0)
        {
            result += ch;
        }
        if (ch == ')' && count-- > 1)
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    string input = "()()()";
    string output = removeOuterParentheses(input);

    cout << "Original string: " << input << endl;
    cout << "String without outer parentheses: " << output << endl;

    return 0;
}
