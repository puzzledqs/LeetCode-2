class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = m + n - 1; i >= n; i--) {
            A[i] = A[i - n];
        }
        int p = 0;
        int p1 = n, p2 = 0;
        while (p1 < m + n || p2 < n)    {
            if (p2 >= n)    {
                A[p] = A[p1];
                p1++;
                p++;
            }
            else if (p1 >= m + n)    {
                A[p] = B[p2];
                p2++;
                p++;
            }
            else if (A[p1] < B[p2]) {
                A[p] = A[p1];
                p1++;
                p++;
            } 
            else    {
                A[p] = B[p2];
                p2++;
                p++;
            }
        }
    }
};