
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Union of Two Sorted Arrays
// find union

int unionno(int arr1[5], int arr2[])
{

 vector<int>unionlist;

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (arr1[i] < arr2[j])
      {
         unionlist = arr1[i];
          i++;
      }
    }
  }
}

int main()
{
  int arr1[5] = {1, 2, 3, 4, 4};
  int arr2[] = {5, 6, 3, 7, 8};
  unionno(arr1, arr2);
  return 0;
}
