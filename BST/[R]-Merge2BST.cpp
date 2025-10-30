/*
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input: root1 = [5, 3, 6, 2, 4]
 
root2 = [2, 1, 3, N, N, N, 7, 6]
 
Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].
Input: root1 = [12, 9, N, 6, 11]

root2 = [8, 5, 10, 2]

Output: [2, 5, 6, 8, 9, 10, 11, 12]
Explanation: After merging and sorting the two BST we get [2, 5, 6, 8, 9, 10, 11, 12].
Constraints:
1 ≤ number of nodes, root->data ≤ 105
*/


/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void drain(stack<Node*>& st, vector<int>& ans) {
        while(!st.empty()) {
            Node* node = st.top(); st.pop();
            ans.push_back(node->data);
            Node* tmp = node->right;
            while(tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
    }
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        Node * curr1 = root1, * curr2 = root2;
        stack<Node*> st1, st2;
        vector<int> ans;
        
        while((curr1 || !st1.empty()) && (curr2 || !st2.empty()))
        {
            while(curr1)
            {
                st1.push(curr1);
                curr1 = curr1->left;
            }
            
            while(curr2)
            {
                st2.push(curr2);
                curr2 = curr2->left;
            }
            
            auto node1 = st1.top(); 
            auto node2 = st2.top();
            
            if(node1->data<node2->data)
            {
                st1.pop();
                ans.push_back(node1->data);
                curr1 = node1->right;
            }
            else
            {
               st2.pop();
               ans.push_back(node2->data);
               curr2 = node2->right; 
            }
        }
        
        if (!st1.empty())
            drain(st1, ans);
        else
            drain(st2, ans);
        
        return ans;
    }
};