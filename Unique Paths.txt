class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m--;
        n--;
        return C(m + n, n);
    }
    
    int C(int m, int k) {
        if (k > m - k)  {
            k = m - k;
        }
        int ans = 1, di = 2;
        for (int i = 0; i < k; i++) {
            ans *= m - i;
            while (di <= k && ans % di == 0)    {
                ans /= di;
                di++;
            }
        }
        return ans;
    }
};