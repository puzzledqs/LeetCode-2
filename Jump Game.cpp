class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rightmost = 0;
        int start = 0;
        while (start <= rightmost && rightmost < n)  {
            rightmost = max(rightmost, start + A[start]);
            start++;
        }
        if (rightmost >= n - 1)
            return true;
        else
            return false;
    }
};