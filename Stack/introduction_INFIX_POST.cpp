#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

//  INFIX expression
// you have given few examples 4 * 2 + 3 < operand >< operator><operand>
//  given expresion is 4*2+3 we can write this these two form (4*3)+2 or 4*(2+3) but only one expression is true

//  according to the precedence
// () {} [], ^, * /, + -
//  note 1 : if we have * and / both in the expression like 4*23/5 in this case we will be solved left to right  means * then /
//  note2: in case of  2^3^4^8 right to left solve 4^8 firtly solve

//  PREFIX EXPRESSION(polish notation)

// you have given few examples infix 4 * 2 + 3  this is prefix +*432  <operator><operand><operand>
/*
int postfix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    cout << postfix("46+2/5*7+");
    return 0;
}
*/

// int main()
// {
//     string s = "+";
//     stack<int> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             st.push(s[i] - '0');
//         }
//         int ans = '0';
//         cout << ans << endl;
//     }
//     //  cout<<st.top()<<endl;
// }

#include <iostream>

using namespace std;

int main()
{
    char c;

    cout << "Enter a character: ";
    cin >> c;

    int asciiValue = (int)c;

    cout << "The ASCII value of character " << c << " is " << asciiValue << endl;

    return 0;
}