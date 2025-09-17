/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/


class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];      // Stick to visited trick
        board[i][j] = '#';            // mark as visited
        
        // Try all 4 directions
        bool found = dfs(board, i-1, j, word, idx+1)
                  || dfs(board, i+1, j, word, idx+1)
                  || dfs(board, i, j-1, word, idx+1)
                  || dfs(board, i, j+1, word, idx+1);
        
        board[i][j] = temp;           // unmark
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0))   // start dfs from every cell
                    return true;
            }
        }
        return false;
    }
};