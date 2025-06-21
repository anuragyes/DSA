#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

// int main()
// {
//     //  this is the first wya to give the  answer
//     vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
//     int n = 7;
// sort(nums.begin(), nums.end());
// int n = nums.size();
// cout << nums[n / 2];

//  this is the second wya to give the  answer
/*
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                cnt++;
            }
            if (cnt > n / 2)

            cout << arr[i];
        }




    }
     */
//  this is the better solution to solve this question

// map<int, int> solve;
// for (int i = 0; i < arr.size(); i++)
// {
//     solve[arr[i]]++;
// }
// for (auto it : solve)
// {
//     if (it.second > (arr.size() / 2))
//     {
//         // return it.first;
//         cout << it.first << endl;
//     }
// }
// return -1;

//  second way to find the majorty element
//  best approch
/*
    int cnt = 0;
    int el;
    int ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int counter1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            counter1++;
    }
    if (counter1 > (n / 2))
    {
        cout<< el;
    }
    return -1;
}
*/

int main()
{
    int a = -2;
    int b = -2;
    if (a >= b)
    {
        cout << "ye";
    }
    cout << "no";
}
