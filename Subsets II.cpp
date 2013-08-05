class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        vector<int> num;
        
        sort(S.begin(), S.end());
        
        ans.push_back(num);
        DFS(ans, num, S, 0);
        
        return ans;
    }
    
    void DFS(vector<vector<int> > &ans, vector<int> &num, vector<int> &S, int n)  {
        if (n >= S.size())
            return;
        int end = n;
        while (end < S.size() - 1 && S[n] == S[end + 1])    {
            end++;
        }
        DFS(ans, num, S, end + 1);
        for (int i = 0; i <= end - n; i++)  {
            num.push_back(S[n]);
            ans.push_back(num);
            DFS(ans, num, S, end + 1);
        }
        for (int i = 0; i <= end - n; i++)  {
            num.pop_back();
        }
    }
};