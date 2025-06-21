#include <iostream>
#include <stack>
using namespace std;
/*
step 1 : create a stack name s;
step 2 : now write a loop and make a char ch and enter all the element comes from tthe loop
step 3: push all the char  in s stack;
step 4: make a empty string where we will be storing all the elements
 step 5: useing while loop condition is untill stack will not be empty take a top element from s stack and push all the element in anserw which is empty
 step 6: pop all elements  from s;
*/

int main()
{
    string str = "anurag";
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << ans << endl;
}