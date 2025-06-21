#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void longest(string str[], int n)
{

    string answer = "";

    for (int i = 0; i < str[0].length(); i++)
    {
        char ch = str[1][i];

    
        bool match = true;

        for (int j = 1; j < n; j++)
        {

          
            if (str[j].size() < i || ch != str[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            answer.push_back(ch);
    }

    //  return answer;
}

int main()
{
    int size = 5;
    string str[] = {"coding", "codingninja", "coder", "coworker"};
    longest(str, size);
    return 0;
}