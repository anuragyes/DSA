#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

string sortSentence(string s)
{
    vector<string> ans(10);
    string temp = "";
    int index = 0;
    int count = 0;  
     int n = s.size();
    while (index < n)
    {
        if (s[index] == ' ')
        {
            int pos = temp[temp.size() - 1] - '0'; //  put string into at  its right pos
            temp.pop_back();  //pop the int value which is present into at last 
            ans[pos] = temp;   
            temp.clear();
            count++;
        }
        else
            temp += s[index];
        index++;
    }
    int pos = temp[temp.size() - 1] - '0';
    temp.pop_back();
    ans[pos] = temp;
    temp.clear();
    count++;
    for (int i = 1; i <= count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back();

    return temp;
}
