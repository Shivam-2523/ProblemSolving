#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int value) : val(value),left(nullptr),right(nullptr) {}
};
/*
1.Initialize a stack < pair < Node*, int>> say S.
2.Push the root node in the stack with status as 1, i.e {root, 1}.
3.Initialize three vectors of integers say preorder, inorder, and postorder.
4.Traverse the stack until the stack is empty and check for the following conditions:
5.If the status of the top node of the stack is 1 then update the status of the top node of the stack
  to 2 and push the top node in the vector preorder and insert the left child of the top node if it is not NULL in the stack S.
6.If the status of the top node of the stack is 2 then update the status of the top node of the stack
  to 3 and push the top node in the vector inorder and insert the right child of the top node if it is not NULL in the stack S.
7.If the status of the top node of the stack is 3 then push the top node in vector postorder and then pop the top element.
8.Finally, print vectors preorder, inorder, and postorder.
*/
void allTraversal(TreeNode * root, vector<int> & pre, vector<int> & post, vector<int> & in)
{
    stack<pair<TreeNode*, int> > s;
    s.push(make_pair(root, 1));

    while (!s.empty()) {
        pair<TreeNode*, int> p = s.top();

        if (p.second == 1) {
            s.top().second++;
            pre.push_back(p.first->val);
            if (p.first->left) {
                s.push(make_pair(
                    p.first->left, 1));
            }
        }
        else if (p.second == 2) {
            s.top().second++;
            in.push_back(p.first->val);

            if (p.first->right) {
                s.push(make_pair(
                    p.first->right, 1));
            }
        }
        else {
            post.push_back(p.first->val);
            s.pop();
        }
    }
}

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);;
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    allTraversal(root,pre,post,in);
    
    cout<<"PREORDER ---> ";
    for(auto i: pre)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"POSTORDER ---> ";
    for(auto i: post)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"INORDER ---> ";
    for(auto i: in)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}