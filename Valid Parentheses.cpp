public class Solution {
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Character> stack = new ArrayList<Character>();
        for (char ch: s.toCharArray())   {
            if (ch == '(' || ch == '{' || ch == '[')    {
                stack.add(ch);
            }
            else    {
                if (stack.size() == 0)
                    return false;
                if (ch == ')')  {
                    if (stack.remove(stack.size() - 1) != '(')
                        return false;
                }
                else if (ch == '}')  {
                    if (stack.remove(stack.size() - 1) != '{')
                        return false;
                }
                else if (ch == ']')  {
                    if (stack.remove(stack.size() - 1) != '[')
                        return false;
                }
            }
        }
        if (stack.size() == 0)
            return true;
        else
            return false;
    }
}