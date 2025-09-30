/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/


class Solution {
public:
    vector<vector<int>> v {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> & vis)
    {
        if(!vis[i][j])
        {
            vis[i][j] = true;
            for(auto node: v)
            {
                int cr = node[0] + i, cc = node[1] + j;
                if(cr>=0 && cr<board.size() && cc >=0 && cc<board[0].size() && board[cr][cc] == 'O')
                    dfs(cr,cc,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis (m,vector<bool>(n,false));
        for(int i = 0; i<m; i++)
        {
            if(board[i][0] == 'O')
                dfs(i,0,board,vis);
            if(board[i][n-1] == 'O')
                dfs(i,n-1,board,vis);
        }
        for(int i = 0; i<n; i++)
        {
            if(board[0][i] == 'O')
                dfs(0,i,board,vis);
            if(board[m-1][i] == 'O')
                dfs(m-1,i,board,vis);
        }

        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};