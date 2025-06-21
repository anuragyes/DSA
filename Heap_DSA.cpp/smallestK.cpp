#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        // size = size + 1;

        // int index = size;
        // arr[index] = val;
        // while (index > 1)
        // {
        //     int parent = index / 2;
        //     if (arr[parent] < arr[index])
        //     {
        //         swap(arr[parent], arr[index]);
        //         index = parent;
        //     }
        //     else
        //     {
        //         return;
        //     }
        // }
    }

    void deletenode()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        //    put last index in first index
        arr[1] = arr[size];
        //  remove last element;
        size--;
        //  take a root node to its correct position
        int index = 1;
        while (index < size)
        {
            int leftindex = index * 2;
            int rightindex = index * 2 + 1;
            if (leftindex < size && arr[index] < arr[leftindex])
            {
                swap(arr[index], arr[leftindex]);
                index = leftindex;
            }
            else if (rightindex < size && arr[index] < arr[rightindex])
            {
                swap(arr[index], arr[rightindex]);
                index = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int smallestK(int arr[], int l, int r, int k)
{

    priority_queue<int> q;
    //    push all the k elements into  priority queue
    for (int i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
         if (arr[i] < q.top())  // max head made here property of priority queue always store maxheap means lagrest element 
        {
            q.pop();
            q.push(arr[i]);
        }
    }
     int ans = q.top();
     return ans;
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    // h.deletenode();
    // h.print();
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int l = 0;
    int r = 5;
    cout << smallestK(arr, l, r, k);

    return 0;
}