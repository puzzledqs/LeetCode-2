public class Solution {
    boolean[][] rowfill;
    boolean[][] colfill;
    boolean[][] gridfill;
    
    public void solveSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        rowfill = new boolean[9][];
        colfill = new boolean[9][];
        gridfill = new boolean[9][];
        for (int i = 0; i < 9; i++) {
            rowfill[i] = new boolean[9];
            colfill[i] = new boolean[9];
            gridfill[i] = new boolean[9];
            Arrays.fill(rowfill[i], false);
            Arrays.fill(colfill[i], false);
            Arrays.fill(gridfill[i], false);
        }
        
        for (int i = 0; i < board.length; i++)  {
            for (int j = 0; j < board[i].length; j++)  {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (rowfill[i][num] || colfill[j][num] || gridfill[gridID(i, j)][num])
                    return;
                rowfill[i][num] = true;
                colfill[j][num] = true;
                gridfill[gridID(i, j)][num] = true;
            }
        }
        
        DFS(board, 0);
    }
    
    public boolean DFS(char[][] board, int gn)   {
        if (gn >= 81)
            return true;
        int i = gn / 9, j = gn % 9;
        if (board[i][j] != '.') {
            return DFS(board, gn + 1);
        }
        else    {
            for (int num = 0; num < 9; num++)    {
                if (rowfill[i][num] || colfill[j][num] || gridfill[gridID(i, j)][num])
                    continue;
                fill(board, i, j, num);
                if (DFS(board, gn + 1))
                    return true;
                unfill(board, i, j, num);
            }
        }
        return false;
    }
    
    public void fill(char[][] board, int i, int j, int num)   {
        rowfill[i][num] = true;
        colfill[j][num] = true;
        gridfill[gridID(i, j)][num] = true;
        board[i][j] = '1';
        board[i][j] += num;
    }
    
    public void unfill(char[][] board, int i, int j, int num)   {
        rowfill[i][num] = false;
        colfill[j][num] = false;
        gridfill[gridID(i, j)][num] = false;
        board[i][j] = '.';
    }
    
    public int gridID(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }
}