/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    vector<int> postorderTraversalUsing2Stack(TreeNode * root)
    {
        if(!root) return{};

        stack<TreeNode*> st1;
        stack<int> st2;

        st1.push(root);

        while(!st1.empty())
        {
            auto t = st1.top();
            st1.pop();
            st2.push(t->val);

            if(t->left) st1.push(t->left);
            if(t->right) st1.push(t->right);
        }
        vector<int> ans;
        while(!st2.empty())
        {
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return{};

        stack<TreeNode*> st1;
        vector<int> ans;

        st1.push(root);

        while(!st1.empty())
        {
            auto t = st1.top();
            st1.pop();
            ans.push_back(t->val);

            if(t->left) st1.push(t->left);
            if(t->right) st1.push(t->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> st;
        vector<int> result;

        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);

            // Push right first so that left is processed first
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
        }

        return result;
    }
};