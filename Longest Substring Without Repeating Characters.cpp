class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mx = 0;
        int right = -1;
        for (int i = 0; i < s.length(); i++)    {
            while (1)   {
                bool add = true;
                for (int j = i; j <= right; j++) {
                    if (s[j] == s[right + 1])   {
                        add = false;
                        break;
                    }
                }
                if (right == s.length() - 1)
                    add = false;
                if (add)    {
                    right++;
                }
                else    {
                    if (right - i + 1 > mx)
                        mx = right - i + 1;
                    break;
                }
            }
        }
        return mx;
    }
};