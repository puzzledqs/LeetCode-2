class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        
        long long a = dividend;
        long long b = divisor;
        
        
        int sign = 1;
        if (a < 0)  {
            sign = -sign;
            a = -a;
        }
        if (b < 0)  {
            sign = -sign;
            b = -b;
        }
        
        int ans = 0;
        while (a >= b)   {
            long long times = 1, num = b;
            while (num + num <= a) {
                num += num;
                times += times;
            }
            a -= num;
            ans += times;
        }
        
        return ans * sign;
    }
};