class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (*p == '\0' && *s != '\0')
            return false;
        if (*s == '\0' && *p == '\0')
            return true;
        if (*p != '.' && *(p + 1) != '*') {
            if (*p == *s)
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
        if (*p != '.' && *(p + 1) == '*') {
            do  {
                if (isMatch(s, p + 2))
                    return true;
                s++;
            } while (*(s - 1) != '\0' && *(s - 1) == *p); 
        }
        if (*p == '.' && *(p + 1) != '*' && *s != '\0')   {
            return isMatch(s + 1, p + 1);
        }
        if (*p == '.' && *(p + 1) == '*') {
            do  {
                if (isMatch(s, p + 2))
                    return true;
                s++;
            } while (*(s - 1) != '\0');
        }
        return false;
    }
};