public class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (strs == null)   {
            return null;
        }
        if (strs.length == 0)   {
            return "";
        }
        String lcp = strs[0];
        for (int i = 1; i < strs.length; i++)   {
            lcp = longestCommonPrefix(lcp, strs[i]);
        }
        return lcp;
    }
    
    private String longestCommonPrefix(String s1, String s2)    {
        StringBuffer cs = new StringBuffer();
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1.charAt(i) == s2.charAt(i))  {
            cs.append(s1.charAt(i));
            i++;
        }
        return cs.toString();
    }
}