
#include <bits/stdc++.h>
using namespace std;

/*xample 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r*/

string merge(string str1, string str2)
{
    string result = "";
    int i = 0;
    while (i < str1.length() || i < str2.length())
    {
        if (i < str1.length())
        {
            result += str1[i];
        }
        if (i < str2.length())
        {
            result += str2[i];
        }
        i++;
    }
    return result;
}

int main()
{
    cout << merge("abc", "pqr");
    return 0;
}