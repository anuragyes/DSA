#include <iostream>
#include <cmath> // For sqrt function
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int number = 18296;
    cout << number / 10000;
    vector<int> ans = {1, 5, 7, 9, 1};
    unordered_map<int, int> maap;

    for (int i = 0; i < ans.size(); i++)
    {
        maap[ans[i]]++;
    }

    for (auto pair : maap)
    {
        cout << pair.first << endl;
    }

    // double squareRoot = sqrt(number);  // Calculate square root of 100
    //   int intResult = static_cast<int>(floor(squareRoot));

    // std::cout << "The square root of " << number << " is " << squareRoot << std::endl;

    // std::cout << "The square root of " << intResult << std::endl;
    return 0;
}
