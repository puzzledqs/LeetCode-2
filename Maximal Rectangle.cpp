// updated 090313
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
            
        int r = matrix.size();
        int c = matrix[0].size();
        
        int ans = 0, nowh, last;
        vector<int> height(c, 0);
        stack<int> si, sh;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '0')    {
                    height[j] = 0;
                }
                else    {
                    height[j]++;
                }
            }
            
            for (int j = 0; j <= c; j++)    {
                nowh = (j == c ? -1 : height[j]);
                
                if (si.empty() || sh.top() < nowh)  {
                    si.push(j);
                    sh.push(nowh);
                }
                else if (sh.top() > nowh)   {
                    while (!si.empty() && nowh < sh.top()) {
                        last = si.top();
                        ans = max(ans, sh.top() * (j - si.top()));
                        si.pop();
                        sh.pop();
                    }
                    si.push(last);
                    sh.push(nowh);
                }
            }
        }
        
        return ans;
    }
};

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
