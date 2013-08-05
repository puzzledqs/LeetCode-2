class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int *a = new int[n + 1];
        for (int i = 0; i <= n; i++)    {
            if (i == 0 || i == 1)   {
                a[i] = 1;
            }
            else    {
                a[i] = 0;
                for (int j = 0; j <= i - 1; j++)    {
                    a[i] += a[j] * a[i - 1 - j];
                }
            }
        }
        return a[n];
    }
};