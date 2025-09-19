#include <bits/stdc++.h>
using namespace std;

string reformDate(string &s)
{
    // Write your code here
    unordered_map<string, string> maap = {

        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"},

    };

    stringstream ss(s);
    string day, month, year;
    ss >> day >> month >> year;

    // extract day
    string numpart;
    for (auto ch : day)
    {

        if (isdigit(ch))
        {
            numpart += ch;
        }
        else
            break;
    }

    if (numpart.size() == 1)
    {
        numpart = "0" + numpart;
    }

    string ans = year + "-" + maap[month] + "-" + numpart;
    return ans;
}
int main()
{
    string date = "27th Oct 2052";
    cout << reformDate(date) << endl; // Output: 2052-10-27
}