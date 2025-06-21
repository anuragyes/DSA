#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]*/

void rotate(vector<int> arr, int size, int k)
{
    //  step first
    reverse(arr.begin(), arr.end());
    //  step second
    for(int i=k;i>0;i--){
        cout<<arr[i]<<endl;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    rotate(arr, size, 3);
    return 0;
}