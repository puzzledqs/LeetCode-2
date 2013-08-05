public class Solution {
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int rn = matrix.length;
        if (rn == 0) 
            return new ArrayList<Integer>();
        int cn = matrix[0].length;
        if (cn == 0) 
            return new ArrayList<Integer>();
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i = 0; i < (Math.min(rn, cn) + 1) / 2; i++)   {
            for (int j = i; j <= cn - 1 - i; j++)
                ans.add(matrix[i][j]);
            for (int j = i + 1; j <= rn - 1 - i - 1; j++)
                ans.add(matrix[j][cn - 1 - i]);
            if (i < rn - 1 - i) {
                for (int j = cn - 1 - i; j >= i; j--)
                    ans.add(matrix[rn - 1 - i][j]);
            }
            if (i < cn - 1 - i)   {
                for (int j = rn - 1 - i - 1; j >= i + 1; j--)
                    ans.add(matrix[j][i]);
            }
        }
    
    
        return ans;
    }
    
}