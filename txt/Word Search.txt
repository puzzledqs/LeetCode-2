class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word == "")
            return true;
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;
            
        for (int i = 0; i < board.size(); i++)  {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (DFS(board, word, i, j, 0))  {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool DFS(vector<vector<char> > &board, string word, int r, int c, int n)  {
        if (board[r][c] != word[n])
            return false;
            
        if (n + 1 == word.length())
            return true;
        
        board[r][c] -= 30;
        bool flag = false;
        if (!flag && r > 0)
            flag = flag || DFS(board, word, r - 1, c, n + 1);
        if (!flag && c > 0)
            flag = flag || DFS(board, word, r, c - 1, n + 1);
        if (!flag && r < board.size() - 1)
            flag = flag || DFS(board, word, r + 1, c, n + 1);
        if (!flag && c < board[0].size() - 1)
            flag = flag || DFS(board, word, r, c + 1, n + 1);
        board[r][c] += 30;
        
        return flag;
    }
};