class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        for (int i = 1; i <= numRows; i++)  {
            vector<int> num;
            num.clear();
            if (i == 1) {
                num.push_back(1);
            }
            else    {
                for (int j = 0; j < i; j++)    {
                    if (j == 0 || j == i - 1)
                        num.push_back(1);
                    else
                        num.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
                }
            }
            ans.push_back(num);
        }
        
        return ans;
    }
};