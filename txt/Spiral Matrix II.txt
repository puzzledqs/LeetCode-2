class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0)
            return vector<vector<int>>(0);
            
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(vector<int>(n));
        }
        
        int c = 1;
        for (int i = 0; i < (n + 1) / 2; i++)   {
            if (c == n * n) {
                ans[i][i] = c;
                break;
            }
            int s = i, e = n - 1 - i;
            for (int j = s; j <= e - 1; j++) {
                ans[s][j] = c;
                c++;
            }
            for (int j = s; j <= e - 1; j++) {
                ans[j][e] = c;
                c++;
            }
            for (int j = e; j >= s + 1; j--) {
                ans[e][j] = c;
                c++;
            }
            for (int j = e; j >= s + 1; j--) {
                ans[j][s] = c;
                c++;
            }
        }
        
        return ans;
    }
};