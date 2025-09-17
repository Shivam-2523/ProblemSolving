/*
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3], key = 3

Output: 2 -1
Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
Constraints: 
1 <= no. of nodes <= 105
1 <= node->data <= 106
1 <= key <= 106
*/


/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void helper(Node* root, int key, Node*& pre, Node*& suc) {
        if (!root) return;
        if (root->data == key) {
            // Predecessor: rightmost in left subtree
            Node* tmp = root->left;
            while (tmp) {
                pre = tmp;
                tmp = tmp->right;
            }
            // Successor: leftmost in right subtree
            tmp = root->right;
            while (tmp) {
                suc = tmp;
                tmp = tmp->left;
            }
        } else if (key < root->data) {
            suc = root; // Current node can be successor
            helper(root->left, key, pre, suc);
        } else { // key > root->data
            pre = root; // Current node can be predecessor
            helper(root->right, key, pre, suc);
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) 
    {
        Node* pre = nullptr; Node* suc = nullptr;
        helper(root, key, pre, suc);
        return {pre, suc};
    }
};