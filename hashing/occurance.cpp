#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 2, 2, 3, 3, 3, 4};

    map<int, int> s;
    for (int element : vec)
    {
        s[element]++;
    }

    for (const auto &pair : s)
    {
        std::cout << "Element " << pair.first << ": " << pair.second << " times\n";
    }
}