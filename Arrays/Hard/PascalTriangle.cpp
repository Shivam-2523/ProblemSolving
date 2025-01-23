/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        if(numRows>1)
            ans.push_back({1,1});

        vector<int> prev = {1,1};
        for(int i = 3; i<=numRows; i++)
        {
            vector<int> v (i,1);
            for(int j = 0; j<prev.size()-1;j++)
                v[j+1]=prev[j]+prev[j+1];
            ans.push_back(v);
            prev = v;
        }
        return ans;
    }
};