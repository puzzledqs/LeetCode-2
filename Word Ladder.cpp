class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        dict.insert(end);
        
        queue<pair<string, int>> q;
        q.push(pair<string, int>(start, 1));
        
        while (!q.empty())  {
            string s = q.front().first;
            int d = q.front().second;
            q.pop();
            
            if (s == end)   {
                return d;
            }
            
            for (int i = 0; i < s.length(); i++)    {
                string tmp = s;
                for (char c = 'a'; c <= 'z'; c++)   {
                    if (s[i] == c)
                        continue;
                    tmp[i] = c;
                    
                    if (dict.find(tmp) != dict.end())   {
                        q.push(pair<string, int>(tmp, d + 1));
                        dict.erase(tmp);
                    }
                }
            }
        }
        
        return 0;
    }
};