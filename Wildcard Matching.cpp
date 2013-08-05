class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const char *stars = NULL, *starp = NULL;
        
        while (*s)    {
            if (*p == '?' || *p == *s)  {
                s++;
                p++;
            }
            else if (*p == '*') {
                while (*p == '*')
                    p++;
                if (!*p)    {
                    return true;
                }
                
                starp = p;
                stars = s;
            }
            else if (starp)   {
                p = starp;
                stars++;
                s = stars;
            }
            else
                return false;
        }
        
        while (*p == '*')
            p++;
        if (*p)
            return false;
        else 
            return true;
    }
};