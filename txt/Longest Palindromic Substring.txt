class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string os = s;
        s = "*";
        for (int i = 0; i < os.length(); i++) {
            s += os[i];
            s += "*";
        }
        
        int right = 0, o = 0;
        int p[2006];
        for (int i = 0; i < s.length(); i++)    {
            if (right > i) {
                p[i] = min(p[2 * o - i], right - i);
            }
            else    {
                p[i] = 1;
            }
            
            while (i + p[i] < s.length() && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])    {
                p[i]++;
            }
            
            if (i + p[i] - 1 > right)   {
                right = i + p[i] - 1;
                o = i;
            }
        }
        
        int mx = 0;
        for (int i = 0; i < s.length(); i++)    {
            if (p[i] > mx)  {
                mx = p[i];
                o = i;
            }
        }
        
        int start = o / 2 - (p[o] - 1) / 2;
        return os.substr(start, p[o] - 1);
    }
};