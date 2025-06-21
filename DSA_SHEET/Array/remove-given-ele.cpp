
#include <bits/stdc++.h>
using namespace std;

/*Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
int remove(int nums[], int size, int val)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}
int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 2, 2};
    int k = 2;
    cout << remove(arr, 7, k);

    return 0;
}