public class Solution {
    public int atoi(String str) {
        // Start typing your Java solution below
        // DO NOT write main() function
        str = str.trim();
        if (str.length() == 0)
            return 0;
            
        int sign = 1;
        int i = 0;
        if (str.charAt(0) == '-')  {
            sign = -1;
            i++;
        }
        else if (str.charAt(0) == '+') {
            i++;
        }
        
        int ans = 0;
        while (i != str.length())   {
            if (str.charAt(i) < '0' || str.charAt(i) > '9')
                break;
                
            if (sign > 0 && (ans > 214748364 || (ans == 214748364 && str.charAt(i) > '7')))
                return 2147483647;
            if (sign < 0 && (ans > 214748364 || (ans == 214748364 && str.charAt(i) > '8')))
                return -2147483648;
                
            ans = ans * 10 + (str.charAt(i) - '0');
            
            
            i++;
        }
        
        
        
        
        return ans * sign;
    }
}