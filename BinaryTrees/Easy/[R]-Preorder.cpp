/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]
*/

ITERATIVE ->

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(!root)
            return {};
            
        s.push(root);
        while(!s.empty())
        {
            TreeNode * temp = s.top();
            ans.push_back(temp->val);
            s.pop();
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return ans;
    }


RECURSIVE ->

  void helper (TreeNode * root, vector<int> & ans)
    {
        if(!root)
            return;
        
        ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }