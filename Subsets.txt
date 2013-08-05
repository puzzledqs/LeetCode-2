class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        
        int p = 0;
        vector<int> now;
        
        sort(S.begin(), S.end());
        
        DFS(ans, S, now, p);
        
        return ans;
    }
    
    void DFS(vector<vector<int> > &ans, vector<int> &S, vector<int> &now, int p)  {
        if (p >= S.size())    {
            ans.push_back(now);
        }
        else    {
            now.push_back(S[p]);
            DFS(ans, S, now, p + 1);
            now.pop_back();
            DFS(ans, S, now, p + 1);
        }
    }
};