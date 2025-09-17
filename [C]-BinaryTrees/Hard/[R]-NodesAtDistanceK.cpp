/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParent(TreeNode * root, TreeNode * target, unordered_map<TreeNode *,TreeNode *> & parentMap)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            if(node->left)
            {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //STEP 1 -> GET THE PARENT MAP
        unordered_map<TreeNode *,TreeNode *> parentMap;
        mapParent(root,target,parentMap);

        //STEP 2 -> Go to level 2 using BFS
        queue<TreeNode *> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int count = -1;
        vector<int> ans;

        while(!q.empty())
        {
            int size = q.size();
            ++count;
            if(count == k)
            {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for(int i = 0; i<size; ++i)
            {
                auto node = q.front(); q.pop();
                if(node->left && !visited.count(node->left))
                {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right))
                {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parentMap[node] && !visited.count(parentMap[node]))
                {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }
        return ans;
    }
};