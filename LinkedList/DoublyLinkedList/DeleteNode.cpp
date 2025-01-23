/*
Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation:

Constraints:
2 <= size of the linked list <= 106
1 <= x <= size of the linked list 
1 <= node->data <= 104
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(head == nullptr)
            return head;
        
        if(x ==1)
        {
            head = head->next;
            head->prev = nullptr;
            return head;
        }
        
        Node * temp = head;
        int c = 1;
        
        while(c!=x-1)
        {
            temp = temp->next;
            c++;
        }
        
        if(temp->next->next == nullptr)//last node needs to be deleted
        {
            temp->next->prev = nullptr;
            temp->next = nullptr;
            return head;
        }
        
        //normal case
        Node * tempNext = temp->next->next;
        temp->next->next = nullptr;
        temp->next->prev = nullptr;
        tempNext->prev = temp;
        temp->next = tempNext;
        
        return head;
    }
};