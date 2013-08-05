class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string now = "";
        string p = "";
        int i = 0;
        while (i < path.length())   {
            if (path[i] == '/') {
                move(now, p);
                p = "";
            }
            else    {
                p += path[i];
            }
            i++;
        }
        move(now, p);
        
        if (now == "")   {
            return "/";
        }
        else    {
            return now;
        }
        
    }
    
    void move(string &str, string p)    {
        if (p == "" || p == ".")    {
            return;
        }
        else if (p == "..") {
            if (str.length() == 0)
                return;
            int flag = str.length() - 1;
            do  {
                flag--;
            } 
            while (flag >= 0 && str[flag] != '/');
            
            if (flag > 0)  {
                str = str.substr(0, flag);
            }
            else    {
                str = "";
            }
        }
        else    {
            str = str + "/" + p;
        }
    }
};