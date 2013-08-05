public class Solution {
    public int jump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int steps[] = new int[A.length];
        Arrays.fill(steps, A.length + 1);
        steps[0] = 0;
        for (int i = 0; i < A.length; i++)  {
            for (int j = Math.min(i + A[i], A.length - 1); j >= i + 1; j--) {
                if (steps[j] < steps[i] + 1)
                    break;
                steps[j] = Math.min(steps[j], steps[i] + 1);
            }
        }
        
        return steps[A.length - 1];
    }
}


public class Solution {
    public int jump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int steps = 0;
        int right = 0, newright;
        
        if (A.length == 1)
            return 0;
        
        while (true)   {
            steps++;
            newright = right;
            for (int i = 0; i <= right; i++)    {
                newright = Math.max(newright, i + A[i]);
            }
            if (newright >= A.length - 1)
                return steps;
            right = newright;
        }
    }
}