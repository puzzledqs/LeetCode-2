public class Solution {
    public String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (nRows == 1)
            return s;
            
        StringBuffer sb[] = new StringBuffer[nRows];
        for (int i = 0; i < nRows; i++)
            sb[i] = new StringBuffer();
            
        int now = 0, delta = 1;
        for (int i = 0; i < s.length(); i++)  {
            sb[now].append(s.charAt(i));
            if (now == 0)   {
                delta = 1;
            }
            if (now == nRows - 1)   {
                delta = -1;
            }
            now += delta;
        }
        
        StringBuffer ans = new StringBuffer();
        for (int i = 0; i < nRows; i++) {
            ans.append(sb[i]);
        }
        return ans.toString();
    }
}