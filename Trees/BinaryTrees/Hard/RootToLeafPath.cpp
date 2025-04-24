/*
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:

Input: root[] = [1, 2, 3, 4, 5]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]] 
Explanation: All possible paths: 1->2->4, 1->2->5 and 1->3
Input: root[] = [1, 2, 3]
       1
    /     \
   2       3
Output: [[1, 2], [1, 3]] 
Explanation: All possible paths: 1->2 and 1->3
Input: root[] = [10, 20, 30, 40, 60]
         10
       /    \
      20    30
     /  \
    40   60
Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All possible paths: 10->20 ->40, 10->20->60 and 10->30
*/

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper (Node * root, vector<vector<int>> & ans,vector<int> v)
    {
        if(!root)
            return;
        
        v.push_back(root->data);
        if(!root->left && !root->right)
        {
            ans.push_back(v);
        }
        helper(root->left,ans,v);
        helper(root->right,ans,v);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,ans,v);
        return ans;
    }
};