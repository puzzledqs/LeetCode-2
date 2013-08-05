class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        map<string, int> record;
        vector<string> ans;
        
        if (strs.size() <= 1)
            return ans;
        
        for (int i = 0; i < strs.size(); i++)   {
            string s = strs[i];
            if (s.length() > 1) {
                sort(s.begin(), s.end());
            }
            if (record.find(s) == record.end()) {
                record.insert(make_pair(s, i));
            }
            else    {
                if (record[s] >= 0) {
                    ans.push_back(strs[record[s]]);
                    record[s] = -1;
                }
                ans.push_back(strs[i]);
            }
        }
        
        return ans;
    }
};