class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (strlen(s) == 0)
            return 0;
        
        int p = strlen(s) - 1;
        while (p >= 0 && s[p] == ' ')   {
            p--;
        }
        int e = p;
        while (p >= 0 && s[p] != ' ')   {
            p--;
        }
        
        return e - p;
    }
};