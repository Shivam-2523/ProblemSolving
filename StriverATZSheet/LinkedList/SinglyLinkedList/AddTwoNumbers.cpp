/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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

        return rev (fut,curr);
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);    
        l2 = rev(l2);

        ListNode * ans = new ListNode();
        ListNode * temp = ans;
        int carry = 0;

        while(l1 && l2)
        {
            temp->next = new ListNode((l1->val+l2->val+carry)%10);
            
            carry = (l1->val+l2->val+carry)/10;
            
            l1=l1->next;
            l2=l2->next;

            temp = temp->next;
        }

        ListNode * left;
        if(l1)
            left = l1;
        else
            left = l2;

        while(left)
        {
            temp->next = new ListNode((left->val+carry)%10);
            carry = (left->val+carry)/10;
            
            left=left->next;  
            temp = temp->next;   
        }

        if(carry)
            temp->next = new ListNode(carry);

        return ans->next;
        
    }
};