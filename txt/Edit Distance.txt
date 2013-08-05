class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int M = max(word1.length(), word2.length());
        int MX = M + 5;
        
        int *a0 = new int[M + 2];
        int *a1 = new int[M + 2];
        
        for (int i = 0; i <= word1.length(); i++)   {
            for (int j = 0; j <= word2.length(); j++)   {
                if (i == 0) {
                    a1[j] = j;
                }
                else if (j == 0)    {
                    a1[j] = i;
                }
                else    {
                    a1[j] = min(a0[j] + 1, a1[j - 1] + 1);
                    if (word1[i - 1] == word2[j - 1])
                        a1[j] = min(a1[j], a0[j - 1]);
                    else
                        a1[j] = min(a1[j], a0[j - 1] + 1);
                }
            }
            
            swap(a0, a1);
        }
        
        return a0[word2.length()];
    }
};