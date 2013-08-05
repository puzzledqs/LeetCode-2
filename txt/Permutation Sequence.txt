class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* jc = new int[n + 2];
        jc[0] = 1;
        for (int i = 1; i <= n; i++)    {
            jc[i] = jc[i - 1] * i;
        }
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        
        k--;
        int ch;
        string ans;
        for (int i = n - 1; i >= 0; i--)    {
            ch = k / jc[i];
            k = k - k / jc[i] * jc[i];
            
            ans += ((char)(a[ch] + '0'));
            a.erase(a.begin() + ch);
        }
        
        return ans;
    }
};