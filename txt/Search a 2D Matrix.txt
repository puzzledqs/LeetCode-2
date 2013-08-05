class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0)
            return false;
        
        int k = searchRow(matrix, target);
        if (k == -1)    {
            return false;
        }   
        
        int l = searchNum(matrix[k], target);
        if (l == -1)    {
            return false;
        }
        else    
            return true;
    }
    
    int searchRow(vector<vector<int> > matrix, int target) {
        if (matrix[0].size() == 0)
            return -1;
        int left = 0; 
        int right = matrix.size() - 1;
        int mid;
        while (left < right)   {
            mid = (left + right + 1) / 2;
            if (target < matrix[mid][0])    {
                right = mid - 1;
            }
            else    {
                left = mid;
            }
        }
        if (left >= 0 && left < matrix.size())
            return left;
        else
            return -1;
    }
    
    int searchNum(vector<int> line, int target) {
        int left = 0; 
        int right = line.size() - 1;
        int mid;
        while (left <= right)   {
            mid = (left + right) / 2;
            if (target < line[mid])    {
                right = mid - 1;
            }
            else if (target > line[mid])   {
                left = mid + 1;
            }
            else
                return mid;
        }
        return -1;
    }
};