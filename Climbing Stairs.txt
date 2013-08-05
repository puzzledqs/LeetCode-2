class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a0, a1, tmp;
        a0 = 1;
        a1 = 1;
        for (int i = 2; i <= n; i++)    {
            tmp = a1;
            a1 = a0 + a1;
            a0 = tmp;
        }
        return a1;
    }
};