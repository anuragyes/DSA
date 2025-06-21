#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> res(k, nullptr);
        int len = 0;
        ListNode *temp = head;

        // Step 1: Find the total length of the list
        while (temp)
        {
            len++;
            temp = temp->next;
        }

        // Step 2: Calculate part sizes
        int partSize = len / k;
        int extra = len % k;

        ListNode *curr = head;
        // for (int i = 0; i < k && curr; ++i)
        // {
        //     res[i] = curr;
        //     int currPartSize = partSize + (extra-- > 0 ? 1 : 0);
        //     for (int j = 1; j < currPartSize; ++j)
        //     {
        //         curr = curr->next;
        //     }
        //     ListNode *next = curr->next;
        //     curr->next = nullptr;
        //     curr = next;
        // }

        return res;
    }
};


 int main(){

    //  plan of five year 

       50 - buffalo revenue 20k perday   profit 10k perday total revenue 70 lakh  net profit 35 lakh
       24 lakh revenue 20 lakh profit   -verni compost 
       within 5 year 

        after five year 

        purchase a land in satna  worth 40lakh 
        next year  starting making house worth 70lakh 
        after 2 year purchase a car worth 30 lakh 

        total 1.5 cr 


          now investing on bussines like track , buffalo , agro land 



       


     return 0;
 }