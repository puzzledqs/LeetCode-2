class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s1.length();;
        if (n != s2.length())   {
            return false;
        }
        vector<vector<vector<bool> > > a(n, vector<vector<bool>>(n, vector<bool>(n, false) ) );
        
        for (int l = 1; l <= n; l++)    {
            for (int p1 = 0; p1 <= n - l; p1++)   {
                for (int p2 = 0; p2 <= n - l; p2++)    {
                    if (l == 1)   {
                        if (s1[p1] == s2[p2])   {
                            a[p1][p2][l - 1] = true;
                        }
                        else    {
                            a[p1][p2][l - 1] = false;
                        }
                    }
                    else    {
                        a[p1][p2][l - 1] = false;
                        for (int i = 1; i < l; i++)   {
                            if ((a[p1][p2][i - 1] && a[p1 + i][p2 + i][l - i - 1]) ||
                                (a[p1][p2 + l - i][i - 1] && a[p1 + i][p2][l - i - 1]))   {
                                a[p1][p2][l - 1] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return a[0][0][n - 1];
    }
};