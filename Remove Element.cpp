public class Solution {
    public int removeElement(int[] A, int elem) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (A.length == 0)
            return 0;
        
        int now = 0, i = 0;
        while (i < A.length)    {
            if (A[i] != elem)   {
                A[now] = A[i];
                now++;
            }
            i++;
        }

        return now;
    }
}