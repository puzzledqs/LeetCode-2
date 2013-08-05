public class Solution {
    public String countAndSay(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        String s = "1";
        StringBuffer ans = new StringBuffer();
        char ch = '0';
        int times = 0;
        
        for (int k = 0; k < n - 1; k++) {
            
            for (int i = 0; i < s.length(); i++)    {
                if (i == 0) {
                    ch = s.charAt(i);
                    times = 1;
                }
                else if (s.charAt(i) != s.charAt(i - 1))   {
                    ans.append("" + times + ch);
                    ch = s.charAt(i);
                    times = 1;
                }
                else    {
                    times++;
                }
            }
            ans.append("" + times + ch);
            
            s = ans.toString();
            ans = new StringBuffer();
        }
        
        return s;
    }
}