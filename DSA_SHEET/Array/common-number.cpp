
/*Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.*/
/*n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.*/

#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> findCommonElements(std::vector<int> &arr1, std::vector<int> &arr2, std::vector<int> &arr3)
{
    std::unordered_set<int> set1(arr1.begin(), arr1.end());
    std::unordered_set<int> set2(arr2.begin(), arr2.end());
    std::unordered_set<int> set3(arr3.begin(), arr3.end());

    std::vector<int> commonElements;
    for (int num : set1)
    {
        if (set2.count(num) && set3.count(num))
        {
            commonElements.push_back(num);
        }
    }

    return commonElements;
}

int main()
{
    std::vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    std::vector<int> arr2 = {6, 7, 20, 80, 100};
    std::vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    std::vector<int> common = findCommonElements(arr1, arr2, arr3);

    std::cout << "Common elements: ";
    for (int num : common)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
