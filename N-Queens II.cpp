class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> vCol(n);
        vector<bool> vLeft(2 * n - 1);
        vector<bool> vRight(2 * n - 1);
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            vCol[i] = false;
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            vLeft[i] = vRight[i] = false;
        }
        
        vector<int> a;
        DFS(ans, a, vCol, vLeft, vRight, 0, n);
        
        return ans;
    }
    
    void DFS(int &ans, vector<int> &a, vector<bool> &vCol, vector<bool> &vLeft, vector<bool> &vRight, int r, int n)   {
        if (r == n)  {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vCol[i] || vLeft[r + i] || vRight[i - r + n - 1])
                continue;
            vCol[i] = vLeft[r + i] = vRight[i - r + n - 1] = true;
            a.push_back(i);
            DFS(ans, a, vCol, vLeft, vRight, r + 1, n);
            a.pop_back();
            vCol[i] = vLeft[r + i] = vRight[i - r + n - 1] = false;
        }
    }
};