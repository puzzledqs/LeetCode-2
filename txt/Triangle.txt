class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int maxN = triangle.size();
        int MX = 200000000;
        
        int *a0 = new int[maxN];
        int *a1 = new int[maxN];
        memset(a0, 0, sizeof(int) * maxN);
        
        for (int i = 0; i < triangle.size(); i++)   {
            for (int j = 0; j < triangle.size(); j++)   {
                if (i == 0) {
                    a1[j] = triangle[0][j];            
                }
                else    {
                    a1[j] = MX;
                    if (j > 0)
                        a1[j] = min(a1[j], a0[j - 1] + triangle[i][j]);
                    if (j < i)
                        a1[j] = min(a1[j], a0[j] + triangle[i][j]);
                }
            }
            
            int *tmp = a0;
            a0 = a1;
            a1 = tmp;
        }
        
        int ans = MX;
        for (int i = 0; i < triangle.size(); i++)   {
            ans = min(ans, a0[i]);
        }
        
        return ans;
    }
};