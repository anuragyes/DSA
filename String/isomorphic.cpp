#include <iostream>
#include <map>
using namespace std;

/*
        map<int, int> solve;
        for (int i = 0; i < arr.size(); i++)
        {
            solve[arr[i]]++;
        }
        for (auto it : solve)
        {
            if (it.second > (arr.size() / 2))
            {
                // return it.first;
                cout << it.first << endl;
            }
        }
        return -1;
        */

void check(string str1, string str2)
{
    // if (str1.size() != str2.size())
    // {
    //     return false;
    // }
    map<char, int> s;
    map<char, int> t;
    for (int i = 0; i < str1.size(); i++)
    {
        {
            s[str1[i]]++;
        }
    }
    for (int i = 0; i < str2.size(); i++)
    {
        t[str2[i]]++;
    }

    for (auto its : s)
    {
        for (auto itt : t)
        {
            if (its.second != itt.second)
            {
                // return false;
                cout << itt.second << endl;
            }
        }
    }
    // return true;
}

int main()
{
    string str1 = "adddeee";
    string str2 = "egg";
    check(str1, str2);
    return 0;
}