/*
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/

class Solution {
public:
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
        Info(bool bst, int sz, int mn, int mx): isBST(bst), size(sz), minVal(mn), maxVal(mx) {}
    };

    Info postorder(Node* root, int &maxSize) {
        if (!root) return Info(true, 0, INT_MAX, INT_MIN);

        Info left = postorder(root->left, maxSize);
        Info right = postorder(root->right, maxSize);

        // Check BST property
        if (left.isBST && right.isBST &&
            root->data > left.maxVal && root->data < right.minVal) {
            int currSize = left.size + right.size + 1;
            maxSize = max(maxSize, currSize);
            int currMin = min(left.minVal, root->data);
            int currMax = max(right.maxVal, root->data);
            return Info(true, currSize, currMin, currMax);
        }
        // Not a BST
        return Info(false, 0, INT_MIN, INT_MAX);
    }

    int largestBst(Node* root) {
        int maxSize = 0;
        postorder(root, maxSize);
        return maxSize;
    }
};