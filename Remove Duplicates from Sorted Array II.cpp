class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || A[i] != A[i - 1]) {
                count = 0;
                A[flag] = A[i];
                flag++;
            }
            else    {
                count++;
                if (count >= 2) {
                }
                else    {
                    A[flag] = A[i];
                    flag++;
                }
            }
        }
        return flag;
    }
};