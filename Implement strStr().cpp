public class Solution {
    public String strStr(String haystack, String needle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (needle.equals(""))
            return haystack;
        if (haystack.equals(""))
            return null;
        
        int[] next = getNext(needle);
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j))
                j = next[j - 1];
            if (haystack.charAt(i) == needle.charAt(j))
                j++;
            if (j == needle.length()) {
                return haystack.substring(i - j + 1);
            }
        }
        return null;
    }
    
    public int[] getNext(String str)    {
        int[] next = new int[str.length()];
        
        int tmp;
        next[0] = 0;
        for (int i = 1; i < next.length; i++)   {
            tmp = next[i - 1];
            while (tmp > 0 && str.charAt(i) != str.charAt(tmp)) {
                tmp = next[tmp - 1];
            }
            if (str.charAt(i) == str.charAt(tmp))   {
                next[i] = tmp + 1;
            }
            else
                next[i] = 0;
        }
        return next;
    }
}