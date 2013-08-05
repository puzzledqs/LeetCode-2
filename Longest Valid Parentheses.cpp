public class Solution {
    public int longestValidParentheses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (s == null || s.length() == 0)
            return 0;
        
        Stack<Integer> stack = new Stack<Integer>();
        
        int maxNum = 0;
        for (int i = 0; i < s.length(); i++)  {
            char ch = s.charAt(i);
            if (ch == '(')  {
                stack.push(i);
            }
            else if (ch == ')') {
                if (!stack.isEmpty() && s.charAt(stack.peek()) == '(')   {
                    int pos = stack.pop();
                    if (stack.isEmpty())    {
                        maxNum = Math.max(maxNum, i + 1);
                    }
                    else    {
                        maxNum = Math.max(maxNum, i - stack.peek());
                    }
                }
                else    {
                    stack.push(i);
                }
            }
        }

        return maxNum;
    }
}