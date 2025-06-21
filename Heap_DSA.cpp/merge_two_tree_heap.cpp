

#include <iostream>
#include <vector>
using namespace std;


//  true solution 
class Solution
{
public:
    void heapify(vector<int> &arr, int i, int n)
    {
        int largest = i;
        int leftchild = 2 * i + 1;
        int rightchild = 2 * i + 2;

        if (leftchild < n && arr[largest] < arr[leftchild])
        {
            largest = leftchild;
        }
        if (rightchild < n && arr[largest] < arr[rightchild])
        {
            largest = rightchild;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        //  optimal approch
        vector<int> ans;
        //   make a priority queue
        for (int i = 0; i < n; i++)
            ans.push_back(a[i]); // push all the element of A into  ans

        for (int j = 0; j < m; j++)
            ans.push_back(b[j]); // push all the element B into ans

        int length = ans.size();
        for (int i = length / 2 - 1; i >= 0; i--)
            heapify(ans, i, length);
        return ans;

        /*
//  brute force approch
    //  store  the ans
     vector<int>ans;
    //   make a priority queue
      priority_queue<int>pq;
      for(int i=0;i<n;i++){
           pq.push(a[i]);  //push all the element of A into queue
      }
           for(int j = 0;j<m;j++){
              pq.push(b[j]);       //push all the element B into queue
           }

            while(!pq.empty()){    // pop the  element from  prioity queue
                 ans.push_back(pq.top());
                 pq.pop();
            }
             return ans;   // return ans;

      */
    }
};