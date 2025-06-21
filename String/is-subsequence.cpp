#include <iostream>
#include <string>
using namespace std;

//  find  string s = "abc" present in string t = "anurag";

bool isSubsequence(string s, string t)
{

    int j = 0;
    for (int i = 0; i < t.size() and j < s.size(); i++)
    {
        if (s[j] == t[i])
        {
            j++;
        }
    }
    return (j == s.size());
}

int main()
{
    cout << isSubsequence("abc", "ahbgdc") << endl;
    cout << isSubsequence("ang", "anurag") << endl;
    cout << isSubsequence("abo", "ahbgdc");
    return 0;
}