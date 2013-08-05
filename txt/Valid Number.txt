class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        bool dot = false, e = false;
        while (i < strlen(s) && s[i] == ' ')   {
            i++;
        }
        if (i >= strlen(s))
            return false;
            
        if (s[i] == '-' || s[i] == '+')
            i++;
        if (i >= strlen(s))
            return false;
        
        while (i < strlen(s))   {
            if (s[i] == ' ')
                break;
            if (invalid(s[i]))
                return false;
            else if (s[i] == 'e' && !e)  {
                e = true;
                dot = true;
                if ((i <= 0 || (!is_num(s[i - 1]) && s[i - 1] != '.')) || (i >= strlen(s) || (!is_num(s[i + 1]) && s[i + 1] != '+' && s[i + 1] != '-')))
                    return false;
                if (s[i + 1] == '-' || s[i + 1] == '+')
                    i++;
                if (i >= strlen(s))
                    return false;
            }
            else if (s[i] == '.' && !dot)   {
                dot = true;
                if ((i <= 0 || !is_num(s[i - 1])) && (i >= strlen(s) || !is_num(s[i + 1])))
                    return false;
            }
            else if (is_num(s[i]))  {
            }
            else 
                return false;
            i++;
        }
        
        if (s[i - 1] == '+' || s[i - 1] == '-')  {
            return false;
        }
        
        while (i < strlen(s) && s[i] == ' ')   {
            i++;
        }
        
        if (i >= strlen(s))
            return true;
        else 
            return false;
    }
    
    bool invalid(char c)    {
        return !is_num(c) && c != 'e' && c != '.';
    }
    
    bool is_num(char c) {
        return c <= '9' && c >= '0';
    }
};