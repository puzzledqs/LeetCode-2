class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int add = 1, i = digits.size() - 1;
        while (add > 0 && i >= 0) {
            digits[i]++;
            add = 0;
            if (digits[i] >= 10)   {
                digits[i] %= 10;
                add = 1;
                i--;
            }
        }
        if (i < 0) {
            digits.insert(digits.begin(), add);
        }
        return digits;
    }
};