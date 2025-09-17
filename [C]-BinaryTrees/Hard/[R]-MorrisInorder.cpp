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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while(curr)
        {
            if(!curr->left)
            {
                result.emplace_back(curr->val);
                curr=curr->right;
            }
            else
            {
                auto node = curr->left;
                //go to rightmost
                while(node->right && node->right!=curr)
                    node = node->right;
                
                //thread already there
                if(node->right == curr)
                {
                    result.push_back(curr->val);
                    node->right = nullptr;
                    curr = curr->right;
                }else
                {
                    node->right = curr;
                    curr = curr->left;
                }
            }
        }

        return result;
    }
};