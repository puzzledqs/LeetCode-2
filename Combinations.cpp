class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if (k == 0)
            return ans;
        
        vector<int> tmp;
        Add(ans, tmp, n, k, n);
        return ans;
    }
    
    void Add(vector<vector<int> > &ans, vector<int> &v, int n, int k, int total)  {
        if (v.size() + n < k)   {
            return;
        }
        else if (v.size() == k)  {
            ans.push_back(v);
            return;
        }
        else    {
            v.push_back(total - n + 1);
            Add(ans, v, n - 1, k, total);
            v.pop_back();
            Add(ans, v, n - 1, k, total);
        }
    }
};