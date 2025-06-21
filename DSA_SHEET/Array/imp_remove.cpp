#include <iostream>
#include <vector>
using namespace std;

/*Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/

void remove(int arr[], int size)
{
    // if (size == 1 || size == 2)
    // {
    //     cout << size << endl;
    // }

    // int count = 0;
    // for (int i = 2; i < size; i++)
    // {
    //     if (arr[i] != arr[i - 2])
    //     {
    //         count++;
    //     }
    // }
    // cout << count + 2;

   vector<int>ans={1,23,4,55,4,3};
    for(auto a: ans){
         cout<<a<<endl;
    }

}

int main()
{
    // int arr[] = {0, 0, 1, 1, 1, 1, 2, 2, 2, 3};
    // int size = 10;
    int arr[] = {1, 1, 1, 2, 2, 3};
    int size = 6;
    remove(arr, size);
    return 0;
}