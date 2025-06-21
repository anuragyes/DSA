#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<char> str = {'t', 'r', 'e', 'e'};
    vector<char> ans;
    map<char, int> name;

    for (auto element : str)
    {
        name[element]++;
    }

    for (const auto pair : name)
    {
        // cout << "Element " << pair.first << ": " << pair.second << " times\n";
        cout << endl;
        cout << "Element " << pair.first;
    }

   
    return 0;
}