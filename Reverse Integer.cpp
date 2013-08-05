class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int sign = 1;
        if (x < 0)  {
            sign = -1;
            x = -x;
        }
        
        int ans = 0;
        while (x > 0)   {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        
        return ans * sign;
    }
};