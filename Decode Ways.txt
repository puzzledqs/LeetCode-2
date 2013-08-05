class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.length() == 0)
            return 0;
        
        int a0 = 0, a1 = 0, a2 = 0, tmp;
        int f = 0;
        while (f <= s.length())  {
            tmp = a2;
            a2 = a0;
            a0 = a1;
            a1 = tmp;
            
            if (f == 0) {
                a2 = 1;
            }
            else if (f == 1)    {
                a2 = 0;
                if (s[f - 1] != '0')
                    a2 = a1;
            }
            else    {
                a2 = 0;
                if (s[f - 1] != '0')    {
                    a2 += a1;
                }
                if (s[f - 2] == '1' || (s[f - 2] == '2' && s[f - 1] <= '6'))    {
                    a2 += a0;
                }
            }
            
            f++;
        }
        
        return a2;
    }
};