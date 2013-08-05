class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = board.size();
        if (!r) return;
        int c = board[0].size();
        if (!c) return;
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Q';
                q.push(pair<int, int>(i, 0));
            }
            if (board[i][c - 1] == 'O') {
                board[i][c - 1] = 'Q';
                q.push(pair<int, int>(i, c - 1));
            }
        }
        
        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'Q';
                q.push(pair<int, int>(0, i));
            }
            if (board[r - 1][i] == 'O') {
                board[r - 1][i] = 'Q';
                q.push(pair<int, int>(r - 1, i));
            }
        }
        
        while (!q.empty())  {
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();
            
            if (nr > 0 && board[nr - 1][nc] == 'O') {
                board[nr - 1][nc] = 'Q';
                q.push(pair<int, int>(nr - 1, nc));
            }
            if (nr < r - 1 && board[nr + 1][nc] == 'O') {
                board[nr + 1][nc] = 'Q';
                q.push(pair<int, int>(nr + 1, nc));
            }
            if (nc > 0 && board[nr][nc - 1] == 'O') {
                board[nr][nc - 1] = 'Q';
                q.push(pair<int, int>(nr, nc - 1));
            }
            if (nr < c - 1 && board[nr][nc + 1] == 'O') {
                board[nr][nc + 1] = 'Q';
                q.push(pair<int, int>(nr, nc + 1));
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'Q')
                    board[i][j] = 'O';
            }
        }
    }
};