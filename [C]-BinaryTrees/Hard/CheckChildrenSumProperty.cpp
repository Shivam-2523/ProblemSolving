/*
Given the root of a binary tree, determine whether the tree satisfies the Children Sum Property. In this property, each non-leaf node must have a value equal to the sum of its left and right children's values. A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.
Return true if every node in the tree satisfies this condition, otherwise return false.

Examples:

Input: root = [35, 20, 15, 15, 5, 10, 5]

Output: True
Explanation: Here, every node is sum of its left and right child.
Input: root = [1, 4, 3, 5]
  
Output: False
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
	
	bool helper(Node * root)
	{
		if(!root) return true;
		
		if(!root->left && !root->right) return true;
	
		auto left = (root->left) ? (root->left->data) : 0;
		auto right = (root->right) ? (root->right->data) : 0;
		if((root->data == left + right) && helper(root->left) && helper(root->right))
			return true;
		
		return false;
	}
    int isSumProperty(Node *root) {
        // Add your code here
		return (helper(root) ? 1 : 0);
    }
};