/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:
 
Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
 */


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void getLeafs (vector<int> & v, Node * root)
    {
        if(!root) return;
        getLeafs(v, root->left);
        if(!root->left && !root->right)
            v.emplace_back(root->data);
        getLeafs(v, root->right);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> v;
        if(!root) return v;

        if(root->left || root->right)
            v.emplace_back(root->data);

        // Left Boundary
        Node * temp = root->left;
        while(temp) {
            if(temp->left || temp->right)
                v.emplace_back(temp->data);
            if(temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }

        // Leaf Nodes
        getLeafs(v, root);

        // Right Boundary
        vector<int> t;
        temp = root->right;
        while(temp) {
            if(temp->left || temp->right)
                t.emplace_back(temp->data);
            if(temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        reverse(t.begin(), t.end());
        for(auto i: t)
            v.emplace_back(i);

        return v;
    }
};