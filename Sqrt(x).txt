class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = 46340;
        return sqrtm(x, left, right);
    }
    
    int sqrtm(int x, int left, int right)    {
        if (left == right)
            return left;
        int m = (left + right + 1) / 2;
        if (m * m > x) {
            return sqrtm(x, left, m - 1);
        }
        else 
            return sqrtm(x, m, right);
    }
};