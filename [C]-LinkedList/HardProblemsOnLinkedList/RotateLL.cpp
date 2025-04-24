/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;

        int n = 0;
        ListNode * temp = head;

        while(temp)
        {
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k==0)
            return head;
            
        int a = 1;
        temp = head;

        while(a!=n-k)
        {
            a++;
            temp = temp->next;
        }
        ListNode * ans = nullptr;
        ans = temp->next;

        temp->next = nullptr;
        ListNode * t = ans;
        while(t->next)
        {
            t = t->next;
        }
        t->next = head;
        return ans;
    }
};