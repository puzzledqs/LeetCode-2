class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return search(A, target, 0, n - 1);
    }
    
    int search(int A[], int target, int left, int right) {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (target == A[mid])
            return mid;
        if (A[mid] >= A[left])  {
            if (target > A[mid] || target < A[left])    {
                return search(A, target, mid + 1, right);
            }
            else    {
                return search(A, target, left, mid - 1);
            }
        }
        else    {
            if (target < A[mid] || target > A[right])    {
                return search(A, target, left, mid - 1);
            }
            else    {
                return search(A, target, mid + 1, right);
            }
        }
    }
};