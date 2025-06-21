#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        //   binary search  like solved u
        Node* temp = head;
        while(temp -> next != NULL)
        {
            temp =temp -> next;
        }
        // Node* tail = temp;
        vector<pair<int, int>>v;
        Node* left = head;
        Node* right = temp;
        while(left -> data < right -> data)
        {
            if(left -> data + right -> data== target)
            {
                v.push_back({left -> data,right -> data});
              //  v.push_back(right -> data);
                left = left -> next;
                right = right -> prev;
            }
            else if(left -> data + right -> data < target)
            {
                left = left -> next;
            }
            else
            {
                right = right -> prev;
            }
        }
        return v;
    }
};*/