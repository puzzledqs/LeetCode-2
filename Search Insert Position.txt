class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return search(A, target, 0, n - 1);
    }
    
    int search(int A[], int target, int left, int right)    {
        if (left == right)  {
            if (target <= A[left])   {
                return left;
            }
            else    {
                return left + 1;
            }
        }
        int mid = (left + right) / 2;
        if (target > A[mid])   {
            return search(A, target, mid + 1, right);
        }
        else    {
            return search(A, target, left, mid);
        }
    }
};