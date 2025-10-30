/*
Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/

class Solution {
public:
    void mapParents(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            if (cur->data == target) targetNode = cur;
            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    
    int minTime(Node* root, int target) {
        // Step 1: map parents and find pointer to target node
        unordered_map<Node*, Node*> parent;
        Node* targetNode = nullptr;
        mapParents(root, parent, targetNode, target);
        // Step 2: BFS burn simulation
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        int time = -1;
        while (!q.empty()) {
            int sz = q.size();
            ++time;
            for (int i = 0; i < sz; ++i) {
                Node* cur = q.front(); q.pop();
                if (cur->left && !visited.count(cur->left)) {
                    visited.insert(cur->left);
                    q.push(cur->left);
                }
                if (cur->right && !visited.count(cur->right)) {
                    visited.insert(cur->right);
                    q.push(cur->right);
                }
                if (parent[cur] && !visited.count(parent[cur])) {
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }
        }
        return time;
    }
};