class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (a == "" && b == "")
            return 0;
        
        int p1 = a.length() - 1;
        int p2 = b.length() - 1;
        int carry = 0, digit = 0;
        string c = "";
        while (p1 >= 0 || p2 >= 0 || carry >= 1)  {
            digit = carry;
            if (p1 >= 0)    {
                digit += a[p1] - '0';
            }
            if (p2 >= 0)    {
                digit += b[p2] - '0';
            }
            
            
            c += ('0' + digit % 2);
            carry = digit / 2;
            p1--;
            p2--;
        }
        reverse(c);
        return c;
    }
    
    void reverse(string &str)  {
        for (int i = 0; i < str.length() / 2; i++)  {
            swap(str[i], str[str.length() - 1 - i]);
        }
    }
};