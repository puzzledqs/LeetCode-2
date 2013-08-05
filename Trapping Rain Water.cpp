public class Solution {
    public int trap(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] B = A.clone();
        for (int i = 1; i < A.length; i++)  {
            if (B[i] < B[i - 1])
                B[i] = B[i - 1];
        }
        int[] C = A.clone();
        for (int i = A.length - 2; i >= 0; i--)  {
            if (C[i] < C[i + 1])
                C[i] = C[i + 1];
        }
        
        int ans = 0;
        for (int i = 0; i < A.length; i++)  {
            ans += Math.min(B[i], C[i]) - A[i];
        }
        
        return ans;
    }
}