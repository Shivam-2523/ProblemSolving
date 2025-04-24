/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:
*/

ITERATIVE ->

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            // Reach the leftmost node
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            // Process the node at the top of the stack
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            // Visit the right subtree
            curr = curr->right;
        }

        return result;
    }


RECURSIVE ->

    void inorder (TreeNode* root, vector<int> & ans)
    {
        if(!root)
            return;

        inorder (root->left, ans);
        ans.push_back (root->val);
        inorder (root->right, ans);
   
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder (root, ans);

        return ans;
    }