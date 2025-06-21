

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution 
{
    public:
    
    //Function to find minimum number of pages.
    bool ispossible(int A[], int n, int m, int mid) {
  int student = 1;
  int page = 0;
  for (int i = 0; i < n; i++) {
    if (page + A[i] <= mid) {
      page += A[i];
    } else {
      student++;
      if (student > m || A[i] > mid) {
        return false;
      }
      page = A[i];
    }
  }
  return true;
}
    int findPages(int A[], int n, int m) 
    {
        //  edge case 
         if(m>n)
          return -1;
          
  int start = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += A[i];
  }
  int end = sum;
  int ans = -1;
  int mid = start+( end- start) / 2;
  while (start <= end) {

    if (ispossible(A, n, m, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  mid = start+( end- start) / 2;
  }
  return ans;
    }
};