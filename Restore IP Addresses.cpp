class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        vector<string> ans;
        string tmp = "";            
        
        DFS(ans, tmp, s, 0, 0);
        
        return ans;
    }
    
    void DFS(vector<string> &ans, string &tmp, string &s, int i, int n) {
        int num = 0;
        int start = i;
        while (i < s.length())  {
            num = num * 10 + (int)(s[i] - '0');
            if (num == 0)   {
                if (n == 3 && i == s.length() - 1)
                    ans.push_back(tmp + "0");
                else if (n < 3) {
                    string str = tmp + "0.";
                    DFS(ans, str, s, i + 1, n + 1);
                }
                return;
            }
            if (num > 255)
                return;
            if (n == 0) {
                string str = tmp + toString(num) + ".";
                DFS(ans, str, s, i + 1, n + 1);
            }
            else    {
                if (n == 3) {
                    if (i == s.length() - 1)
                        ans.push_back(tmp + toString(num));
                }
                else    {
                    string str = tmp + toString(num) + ".";
                    DFS(ans, str, s, i + 1, n + 1);
                }
            }
            i++;
        }
    }
    
    string toString(int i)    {
        if (i == 0)
            return "0";
        string s;
        stringstream ss;
        ss<<i;
        ss>>s;
        return s;
    }
};