class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.length() == 0)
            return true;
            
        int now = 0, p = 0;
        while (p < s.length())  {
            if (s[p] >= 'A' && s[p] <= 'Z') {
                s[now] = s[p] + 32;
                now++;
                p++;
            }
            else if ((s[p] >= 'a' && s[p] <= 'z') || (s[p] >= '0' && s[p] <= '9')) {
                s[now] = s[p];
                now++;
                p++;
            }
            else    {
                p++;
            }
        }
        
        for (int i = 0; i < now / 2; i++)   {
            if (s[i] != s[now - 1 - i])
                return false;
        }
        
        return true;
    }
};