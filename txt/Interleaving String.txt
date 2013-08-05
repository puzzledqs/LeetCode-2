class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        //bool ans = true;
        //ans = check(s3, s1, s2);
        //return sort(s1 + s2) == sort(s3);
        //return ans;
        /*
        if (s3.length() != s1.length() + s2.length())
            return false;
        
        int times[256];
        memset(times, 0, sizeof(times));
        for (int i = 0; i < s1.length(); i++)   {
            times[s1[i]]++;
        }
        for (int i = 0; i < s2.length(); i++)   {
            times[s2[i]]++;
        }
        for (int i = 0; i < s3.length(); i++)   {
            times[s3[i]]--;
            if (times[s3[i]] < 0)
                return false;
        }
        return true;
        */
        
        if (s3.length() != s1.length() + s2.length())
            return false;
        if (s1 == "")
            return s3 == s2;
        if (s2 == "")
            return s3 == s1;
        
        bool **v = new bool*[s1.length() + 1];
        for (int i = 0; i <= s1.length(); i++)   {
            v[i] = new bool[s2.length() + 1];
        }
        
        for (int i = 0; i <= s1.length(); i++)   {
            for (int j = 0; j <= s2.length(); j++)   {
                if (i == 0 && j == 0)
                    v[i][j] = true;
                else    {
                    if (i > 0 && v[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                        v[i][j] = true;
                    else if (j > 0 && v[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                        v[i][j] = true;
                    else
                        v[i][j] = false;
                }
            }
        }
        
        return v[s1.length()][s2.length()];
    }
    
    bool check(string s3, string s1, string s2)  {
        int p1 = 0, p2 = 0;
        if (s3.length() != s1.length() + s2.length())  {
            return false;
        }
        else    {
            int p3 = 0;
            while (p1 < s1.length() || p2 < s2.length())    {
                if (p1 < s1.length() && s1[p1] == s3[p3])   {
                    p1++; p3++;
                }
                else if (p2 < s2.length() && s2[p2] == s3[p3])   { 
                    p2++; p3++;
                }
                else    {
                    return false;
                }
            }
        }   
        return true;
    }
};