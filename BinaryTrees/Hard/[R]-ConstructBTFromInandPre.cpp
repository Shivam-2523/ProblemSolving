/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

class Solution {
public:
    unordered_map<int,int> inMap;

    TreeNode* helper(const vector<int>& preorder, int preStart, int preEnd,
                     const vector<int>& inorder, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int index = inMap[rootVal];

        int leftSize = index - inStart;

        root->left = helper(preorder, preStart + 1, preStart + leftSize,
                            inorder, inStart, index - 1);

        root->right = helper(preorder, preStart + leftSize + 1, preEnd,
                             inorder, index + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;
        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};