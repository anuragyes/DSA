#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;


    Node(int val) : data(val), next(nullptr) {}
};

  class Solution {
  public:
  Node* partition(Node* head, Node* end){
        Node* pivot=head ;
        Node* curr=head->next ;
        Node* prev=head ;
        while(curr!=end->next){
            if(pivot->data>curr->data){
                swap(prev->next->data, curr->data);
                prev=prev->next ;
            }
            curr=curr->next ;
        }
        swap(prev->data, pivot->data);
        return prev ;
    }
    Node* sort(Node* head,Node* end){
        if(head==NULL || head == end) return head ;
        Node* p=partition(head,end);
        sort(head, p);
        sort(p->next, end);
        
    }
    struct Node* quickSort(struct Node* head) {
       if(head==NULL ||head->next == NULL) return head ;
        Node* start=head;
        while(start->next!=NULL){
            start=start->next;
        }
        Node* end=start ;
        sort(head,end);
        return head ;
    }
};

//  by striver 

 #include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}