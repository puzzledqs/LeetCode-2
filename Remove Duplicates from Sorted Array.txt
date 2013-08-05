public class Solution {
    public int removeDuplicates(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (A.length == 0)
            return 0;
        
        int i = 0, now = 0;
        while (i < A.length)    {
            if (i == 0 || A[i] != A[i - 1]) {
                A[now] = A[i];
                now++;
            }
            i++;
        }
        return now;
    }
}