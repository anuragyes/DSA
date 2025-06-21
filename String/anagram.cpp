#include <iostream>
#include <algorithm>
using namespace std;

bool isanagram(string str1, string str2)
{

    if (str1.length() != str2.length())
    {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 == str2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string str1 = "cat";
    string str2 = "act";

    cout << isanagram(str1, str2) << endl;
    return 0;
}