/* find the numbers which are occurance ? */

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 4, 5, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    map<int, int> count;

    // Counting occurrences of each element
    for (int i = 0; i < size; ++i)
    {
        count[arr[i]]++;
    }

    // Displaying the count of each element
    cout << "Element : Occurrences" << endl;
    for (auto pair : count)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
