class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(rowIndex + 1);
        
        for (int i = 0; i <= rowIndex; i++) {
            if (i == 0) {
                ans[i] = 1;
            }
            else if (i <= rowIndex / 2)  {
                    ans[i] = (int)(0.5 + (double)ans[i - 1] * (rowIndex - i + 1) / i);
            }
            else    {
                ans[i] = ans[rowIndex - i];
            }
        }
        
        return ans;
    }
};