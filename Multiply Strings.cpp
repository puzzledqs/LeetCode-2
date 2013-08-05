public class Solution {
    public String multiply(String num1, String num2) {
        // Start typing your Java solution below
        // DO NOT write main() function        
        StringBuffer ans = new StringBuffer("");
        for (int i = 0; i < num2.length(); i++) {
            ans.append('0');
            ans = add(ans, multiply(num1, (num2.charAt(i) - '0')));
        }
        
        int flag = 0;
        while (flag < ans.length() - 1 && ans.charAt(flag) == '0') {
            flag++;
        }
        
        return ans.substring(flag);
    }
    
    public StringBuffer multiply(String num1, int n)  {
        StringBuffer s1 = new StringBuffer(num1);
        s1.reverse();
        StringBuffer s3 = new StringBuffer();
        int p1 = 0;
        int carry = 0, digit = 0;
        while (p1 < s1.length() || carry > 0)   {
            int tmp = carry;
            if (p1 < s1.length())   {
                tmp += ((s1.charAt(p1) - '0') * n);
            }
            carry = tmp / 10;
            digit = tmp % 10;
            char ch = '0';
            ch += digit;
            s3.append(ch);
            p1++;
        }
        s3.reverse();
        return s3;
    }
    
    public StringBuffer add(StringBuffer num1, StringBuffer num2) {  
        StringBuffer s1 = new StringBuffer(num1);
        s1.reverse();
        StringBuffer s2 = new StringBuffer(num2);
        s2.reverse();
        StringBuffer s3 = new StringBuffer();
        int p1 = 0, p2 = 0;
        int carry = 0, digit = 0;
        while (p1 < s1.length() || p2 < s2.length() || carry > 0)   {
            int tmp = carry;
            if (p1 < s1.length())   {
                tmp += (s1.charAt(p1) - '0');
            }
            if (p2 < s2.length())   {
                tmp += (s2.charAt(p2) - '0');
            }
            carry = tmp / 10;
            digit = tmp % 10;
            char ch = '0';
            ch += digit;
            s3.append(ch);
            p1++;
            p2++;
        }
        s3.reverse();
        return s3;
    }
}