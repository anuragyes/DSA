#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{

    int arr[10] = {1, 4, 3, 4, 1, 2, 3, 4, 4, 4};
    int n = 10;
    unordered_map<int, int> umap;
    int maxFrequency = -1;
    int value = -1;

    //    push all the element into unordered_map
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    for (auto it : umap)
    {
        if (it.second > maxFrequency)
        {
            maxFrequency = it.second;
            value = it.first;
        }
    }
    cout << value << " " << maxFrequency;

    return 0;
}