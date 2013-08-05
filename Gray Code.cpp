class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = 1 << n;
        vector<int> ans(n);
        ans[0] = 0;
        int mx = 1;
        for (int i = 1; i < n; i++) {
            if (i >= mx)   {
                ans[i] = ans[i - 1] ^ mx;
                mx = mx << 1;
            }
            else    {
                ans[i] = ans[i - 1] ^ (ans[i - (mx >> 1)] ^ ans[i - (mx >> 1) - 1]);
            }
        }        
        return ans;
    }
};