/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "N,";
            }
        }
        // Optionally, remove trailing comma
        if (!ans.empty()) ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data[0] == 'N') return nullptr;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root =  new TreeNode(stoi(val));
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Left
            if (getline(ss, val, ',')) {
                if (val == "N") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }
            
            // Right
            if (getline(ss, val, ',')) {
                if (val == "N") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};