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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode * curr = root;
        vector<int> result;

        while(curr)
        {
            if(!curr->left)
            {
                result.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                auto node = curr->left;
                while(node->right && node->right!=curr)
                    node =  node->right;
                
                //thread is already there
                if(node->right == curr)
                {
                    node->right = nullptr;
                    curr = curr->right;
                }else
                {
                    result.push_back(curr->val);
                    node->right = curr;
                    curr = curr->left;
                }
            }
        }

        return result;
    }
};