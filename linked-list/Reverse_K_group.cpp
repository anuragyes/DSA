/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Reverse first k nodes and return new head
    ListNode* solve(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k-- && curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // new head of reversed part
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Count total nodes
        int count = 0;
        ListNode* ptr = head;
        while (ptr) {
            count++;
            ptr = ptr->next;
        }

        ListNode*  dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (count >= k) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = groupStart;

            // Move to k-th node in the group
            for (int i = 1; i < k; i++) {
                groupEnd = groupEnd->next;
            }

            ListNode* nextGroupStart = groupEnd->next;

            // Reverse this group
            groupEnd->next = nullptr;
            ListNode* newHead = solve(groupStart, k);

            // Connect with previous part
            prevGroupEnd->next = newHead;
            groupStart->next = nextGroupStart;

            // Move to next group
            prevGroupEnd = groupStart;
            count -= k;
        }

        return dummy->next;
    }
};



#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // helper function to check if there are at least k nodes left
    bool hasKNodes(ListNode* head, int k) {
        while (head && k > 0) {
            head = head->next;
            k--;
        }
        return k == 0;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !hasKNodes(head, k)) return head;

        // reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        int count = 0;

        while (curr && count < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }

        // head is now the last node in this group
        // recursively call for the rest of the list
        head->next = reverseKGroup(curr, k);

        return prev; // new head of this segment
    }
};

// ----------- Example usage ----------
int main() {
    // create linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;
    ListNode* newHead = sol.reverseKGroup(head, k);

    // print reversed list
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}
