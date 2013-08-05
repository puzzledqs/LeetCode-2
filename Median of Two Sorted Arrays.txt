class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m + n) % 2 == 0)   {
            return (find(A, m, B, n, (m + n) / 2) + find(A, m, B, n, (m + n) / 2 + 1)) / 2;
        }
        else
            return find(A, m, B, n, (m + n) / 2 + 1);
    }
    
    double find(int A[], int m, int B[], int n, int k)  {
        while (1)   {
            if (m == 0) {
                return B[k - 1];
            }
            else if (n == 0)    {
                return A[k - 1];
            }
            else if (k == 1)    {
                return min(A[0], B[0]);
            }
            else    {
                int pa = max(min(k / 2, m), k - n);
                int pb = k - pa;
                if (A[pa - 1] < B[pb - 1])  {
                    A += pa;
                    m -= pa;
                    k -= pa;
                }
                else if (A[pa - 1] > B[pb - 1])  {
                    B += pb;
                    n -= pb;
                    k -= pb;
                }
                else    {
                    return A[pa - 1];
                }
            }
        }
    }
};