class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        unordered_set<int> numSet;
        
        for (int i = 0; i < num.size(); i++)   {
            numSet.insert(num[i]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < num.size(); i++)    {
            if (numSet.find(num[i]) != numSet.end())    {
                numSet.erase(num[i]);
                
                int total = 1;
                
                int tmp = num[i] - 1;
                while (numSet.find(tmp) != numSet.end())    {
                    numSet.erase(tmp);
                    tmp--;
                    total++;
                }
                
                tmp = num[i] + 1;
                while (numSet.find(tmp) != numSet.end())    {
                    numSet.erase(tmp);
                    tmp++;
                    total++;
                }
                
                ans = max(ans, total);
            }
        }
        
        return ans;
    }
};