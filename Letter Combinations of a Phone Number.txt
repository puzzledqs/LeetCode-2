public class Solution {
    public ArrayList<String> letterCombinations(String digits) {
        // Start typing your Java solution below
        // DO NOT write main() function
        char[][] ch = {{}, {}, 
            {'a', 'b', 'c'}, 
            {'d', 'e', 'f'}, 
            {'g', 'h', 'i'}, 
            {'j', 'k', 'l'}, 
            {'m', 'n', 'o'}, 
            {'p', 'q', 'r', 's'}, 
            {'t', 'u', 'v'}, 
            {'w', 'x', 'y', 'z'}
        };        
        
        if (digits.length() == 0)   {
            ArrayList<String> tmp = new ArrayList<String>();
            tmp.add("");
            return tmp;
        }
        
        ArrayList<String> ans = new ArrayList<String>();
        for (int i = 0; i < digits.length(); i++)    {
            if (i == 0) {
                for (char j : ch[digits.charAt(i) - '0'])   {
                    ans.add(new String("" + j));
                }
            }
            else    {
                ArrayList<String> tmp = new ArrayList<String>();
                for (String s: ans) {
                    for (char j: ch[digits.charAt(i) - '0'])  {
                        tmp.add(new String(s + j));
                    }
                }
                ans = tmp;
            }
        }
        return ans;
    }
}