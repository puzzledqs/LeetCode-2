public class Solution {
    public String intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        StringBuffer ans = new StringBuffer();
        ans.append(Roman(num / 1000 % 10, '=', '-', 'M'));
        ans.append(Roman(num / 100 % 10, 'M', 'D', 'C'));
        ans.append(Roman(num / 10 % 10, 'C', 'L', 'X'));
        ans.append(Roman(num / 1 % 10, 'X', 'V', 'I'));
        return ans.toString();
    }
    
    public String Roman(int num, char ten, char five, char one)  {
        if (num == 9)   {
            return "" + one + ten;
        }
        else if (num == 8)  {
            return "" + five + one + one + one;
        }
        else if (num == 7)  {
            return "" + five + one + one;
        }
        else if (num == 6)  {
            return "" + five + one;
        }
        else if (num == 5)  {
            return "" + five;
        }
        else if (num == 4)  {
            return "" + one + five;
        }
        else if (num == 3)  {
            return "" + one + one + one;
        }
        else if (num == 2)  {
            return "" + one + one;
        }
        else if (num == 1)  {
            return "" + one;
        }
        else    {
            return "";
        }
    }
}