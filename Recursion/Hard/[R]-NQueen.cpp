/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    void helper(int count, int n, vector<int> & row, vector<int> & curr, vector<vector<string>> & ans)
    {
        if(count == n)
        {
            vector<string> board (n,string(n,'.'));
            for(int i = 0; i<n; ++i)
                board[i][curr[i]] = 'Q';//place of the queen at the ith row on the board
            ans.push_back(board);
            return;
        }

        for(int i = 0; i<n; ++i)
        {
            //Three checks needed to see if a queen can be placed at a particular index
            if(row[i]!=-1)
            {
                bool possible = true;
                //IF any of the previous rows are causing a diagonal conflict we can't place the queen here
                for(int r = 0; r<count; ++r)
                {
                    if(abs(count-r) == abs(i-curr[r]))
                    {
                        possible = false;
                        break;
                    }
                }

                if(!possible) continue;
                
                curr.push_back(i);//place the queen
                row[i] = -1;//no more queens in this column now
                helper(count+1,n,row,curr,ans);
                row[i] = 0;
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> curr;
        vector<int> row (n,0);

        helper(0,n,row,curr,ans);
        return ans;
    }
};

