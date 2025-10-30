/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

For the above tree, the output should be 5 8 34 22 25

Examples :

Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input: root[] = [10, 20, 30, 40, 60]
         
Output: [40 20 60 30]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105
 */

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            auto node = t.first;
            auto hd = t.second;
            
            m[hd] = node->data;
            
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        
        vector<int> ans;
        for(auto i: m) ans.push_back(i.second);
        
        return ans;
    }
};