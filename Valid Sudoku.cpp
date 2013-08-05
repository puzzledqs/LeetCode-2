public class Solution {
    boolean[][] rowfill;
    boolean[][] colfill;
    boolean[][] gridfill;
    
    public boolean isValidSudoku(char[][] board) {
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
                    return false;
                rowfill[i][num] = true;
                colfill[j][num] = true;
                gridfill[gridID(i, j)][num] = true;
            }
        }
        
        return true;
    }
    
    public int gridID(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }
}