/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    ListNode * rev (ListNode * curr, ListNode * prev = nullptr)
    {
        if(!curr)
            return prev;

        ListNode * fut = curr->next;
        curr->next = prev;
        return rev(fut,curr);
    }
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head,* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        slow = rev(slow);
        while(slow)
        {
            if(slow->val != fast->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};