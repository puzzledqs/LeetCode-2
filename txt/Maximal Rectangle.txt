class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = matrix.size();
        if (r == 0)
            return 0;
        int c = matrix[0].size();
        if (c == 0)
            return 0;
        
        int MX = r * c + 2;
        vector<vector<int> > sum(r);
        for (int i = 0; i < r; i++)  {
            sum[i] = vector<int>(c);
            for (int j = 0; j < c; j++) {
                sum[i][j] = (matrix[i][j] == '0') ? -MX: 1; 
            }
        }
        
        for (int i = 1; i < r; i++)  {
            for (int j = 0; j < c; j++) {
                sum[i][j] += sum[i - 1][j];
            }
        }
        
        int ans = 0;
        vector<int> tmp(c);
        for (int i = 0; i < r; i++) {
            for (int j = i; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (i == 0)
                        tmp[k] = sum[j][k];
                    else
                        tmp[k] = sum[j][k] - sum[i - 1][k];
                }
                
                int add = 0;
                for (int k = 0; k < c; k++) {
                    add += tmp[k];
                    if (add < 0)
                        add = 0;
                    ans = max(ans, add);
                }
            }
        }
        //if (matrix[0][0] == '0' && matrix[0][1] == '1')
        //    return sum[0][0];
        return ans;
    }
};