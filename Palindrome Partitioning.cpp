class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = s.length();
        
        vector<vector<bool> > isPalin(n + 1, vector<bool>(n + 1, false));
        
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
        
        vector<vector<string> > ans;
        vector<string> now;
        DFS(s, ans, isPalin, now, 0);
        
        return ans;
    }
    
    void DFS(string &s, vector<vector<string> > &ans, vector<vector<bool> > &isPalin, 
             vector<string> &now, int start)    {
                 
        if (start >= s.length())    {
            ans.push_back(now);
            return;
        }
                 
        int l = 1;
        while (start + l - 1 < s.length()) {
            if (isPalin[start][l])  {
                now.push_back(s.substr(start, l));
                DFS(s, ans, isPalin, now, start + l);
                now.pop_back();
            }
            l++;
        }
    }
};