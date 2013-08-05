class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return 0;
        
        int sum = A[0], ans = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] + sum < A[i]) {
                sum = A[i];
            }
            else    {
                sum += A[i];   
            }
            if (sum > ans)  {
                ans = sum;
            }
        }
        
        return ans;
    }
};