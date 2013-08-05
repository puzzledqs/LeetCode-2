class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        int end = n - 1;
        int one = n - 1;
        
        while (start <= one)    {
            if (A[start] == 0)  {
                start++;
            }
            else if (A[start] == 2) {
                swap(A[start], A[end]);
                while (end >= 0 && A[end] == 2) {
                    end--;
                }
                if (one > end)  {
                    one = end;
                }
            }
            else    {
                swap(A[start], A[one]);
                one--;
            }
        }
    }
};