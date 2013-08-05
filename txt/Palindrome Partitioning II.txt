class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = s.length();
        
        vector<vector<bool> > isPalin(n + 1, vector<bool>(n + 1, false));
        vector<int> nCut(n, 0x0FFFFFFF);
        
        for (int i = 0; i <= n; i++)    {
            for (int j = 0; j <= n - i; j++)   {
                if (i == 0 || i == 1) {
                    isPalin[j][i] = true;
                }
                else    {
                    if (s[j] == s[j + i - 1] && isPalin[j + 1][i - 2])
                        isPalin[j][i] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i + 1])  {
                nCut[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                if (isPalin[j][i + 1 - j])
                    nCut[i] = min(nCut[i], nCut[j - 1] + 1);
            }
        }
        
        return nCut[n - 1]; 
    }
};