public class Solution {
    public double pow(double x, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (n == 0)
            return 1;
        
        int absn = Math.abs(n);
        double ans = 1;
        int digit = 1;
        while (digit <= absn && digit < (1<<30)) {
            if ((digit & absn) > 0)  
                ans *= x;
            digit <<= 1;
            x *= x;
        }
        
        if (n < 0)
            ans = 1 / ans;
        return ans;
    }
}