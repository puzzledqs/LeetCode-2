class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> ans;
        string s;
        DFS(ans, s, 0, n);
        return ans;
    }
    
    void DFS(vector<string> &ans, string &s, int left, int n) {
        if (s.length() == 2 * n)    {
            ans.push_back(s);
            return;
        }
        else    {
            int right = s.length() - left;
            if (left < n)   {
                s = s + "(";
                DFS(ans, s, left + 1, n);
                s = s.substr(0, s.length() - 1);
            }
            if (right < left)   {
                s = s + ")";
                DFS(ans, s, left, n);
                s = s.substr(0, s.length() - 1);
            }
        }
    }
};