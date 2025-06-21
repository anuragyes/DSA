#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Function to replace each element of the array with its corresponding rank
// void replaceWithRank(vector<int> &arr)
// {
//     // Create a copy of the original array
//     vector<int> temp = arr;

//     // Sort the copy of the array
//     sort(temp.begin(), temp.end());

//     // Create a map to store the rank of each element
//     unordered_map<int, int> rankMap;

//     // Assign ranks to elements based on their sorted order
//     int rank = 1;
//     for (int i = 0; i < temp.size(); ++i)
//     {
//         if (rankMap.find(temp[i]) == rankMap.end())
//         {
//             rankMap[temp[i]] = rank;
//             ++rank;
//         }
//     }

//     // Replace each element of the array with its corresponding rank
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         arr[i] = rankMap[arr[i]];
//     }
// }

// Function to print the elements of an array
// void printArray(const vector<int> &arr)
// {
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     // Example usage
//     vector<int> arr = {4, 7, 2, 90};

//     // cout << "Original array: ";
//     // printArray(arr);

//     replaceWithRank(arr);

//     cout << "Array after replacing with ranks: ";
//     // printArray(arr);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	for (int i = 0; i < n; i++)
	{
		set<int> s;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				s.insert(arr[j]);
			}
		}
		cout << s.size() + 1 << " ";
	}
}