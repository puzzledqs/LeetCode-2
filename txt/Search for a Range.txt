class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ans;
        int start, end;
        
        start = searchStart(A, target, 0, n - 1);
        end = searchEnd(A, target, 0, n - 1);
        
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
    }
    
    int searchStart(int A[], int target, int left, int right)   {
        if (left > right)
            return -1;
        if (left == right && A[left] == target)
            return left;
        if (A[left] > target || A[right] < target)
            return -1;
        int mid = (left + right) / 2;
        if (target > A[mid])    {
            return searchStart(A, target, mid + 1, right);
        }
        else    {
            return searchStart(A, target, left, mid);
        }
    }
    
    int searchEnd(int A[], int target, int left, int right)   {
        if (left > right)
            return -1;
        if (left == right && A[left] == target)
            return left;
        if (A[left] > target || A[right] < target)
            return -1;
        int mid = (left + right + 1) / 2;
        if (target >= A[mid])    {
            return searchEnd(A, target, mid, right);
        }
        else    {
            return searchEnd(A, target, left, mid - 1);
        }
    }
};