/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
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
    void helper (TreeNode * root, vector<vector<int>> & ans)
    {
        if(!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            int len = q.size();
            vector<int> v;
            for(int i = 0; i <len; i++)
            {
                TreeNode * temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root,ans);
        int n = ans.size();

        for(int i = 0; i<n; i++)
        {
            if(i%2!=0)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};