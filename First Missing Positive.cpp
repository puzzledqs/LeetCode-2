public class Solution {
    public int firstMissingPositive(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int num = A.length;
        int meet = 0;
        while (num > meet)    {
            if (A[meet] == meet + 1)    {
                meet++;
            }
            else if (A[meet] < meet + 1 || A[meet] - 1 > num - 1 || A[meet] == A[A[meet] - 1])  {
                int tmp = A[num - 1];
                A[num - 1] = A[meet];
                A[meet] = tmp;
                num--;
            }
            else    {
                int tmp = A[A[meet] - 1];
                A[A[meet] - 1] = A[meet];
                A[meet] = tmp;
            }
        }
        
        return meet + 1;
    }
}