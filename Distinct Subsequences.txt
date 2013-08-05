class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.length() == 0 || T.length() == 0)
            return 0;
        
        vector<vector<int> > f(T.length(), vector<int>(S.length(), 0));
        
        for (int i = 0; i < T.length(); i++)    {
            for (int j = 0; j < S.length(); j++)    {
                f[i][j] = 0;
                if (i == 0) {
                    if (j > 0)  {
                        f[i][j] += f[i][j - 1];
                    }
                    if (T[i] == S[j])   {
                        f[i][j]++;
                    }
                }
                else    {
                    if (j > 0)  {
                        f[i][j] += f[i][j - 1];
                        if (T[i] == S[j])   {
                            f[i][j] += f[i - 1][j - 1];
                        }
                    }
                }
            }
        }
        
        return f[T.length() - 1][S.length() - 1];
    }
};