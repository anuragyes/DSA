#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int array[] = {1, 2, 2, 1, 1, 3};
    int size = sizeof(array) / sizeof(array[0]);

    unordered_map<int, int> countMap;

    // Count occurrences
    for (int i = 0; i < size; ++i)
    {
        countMap[array[i]]++;
    }

    // // Display occurrences
    // for (const auto& pair : countMap) {
    //     std::cout << "Element " << pair.first << " occurs " << pair.second << " times." << std::endl;
    // }

    

        return 0;
}
