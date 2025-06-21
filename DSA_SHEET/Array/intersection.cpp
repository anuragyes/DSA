#include <iostream>
#include <set>
using namespace std;

//  find the intersection(common element) but not duplicate  of two sorted array

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 10};
    int n = 7;
    int arr2[] = {1, 2, 4, 6, 8, 9, 10};
    int m = 7;
    set<int> number; // set to store the common values

    for (int i = 0; i < n; i++) // using loops to check arr1 and arr2 element both are present or not
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j]) // if  element present in both array  insert the element into set
            {
                number.insert(arr1[i]);
            }
        }
    }

    //  using loop for print the set values
    set<int>::iterator itr;
    for (itr = number.begin();
         itr != number.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}