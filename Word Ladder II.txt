class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        dict.insert(end);
        
        queue<pair<pair<string, int>, vector<string> > > q;
        q.push(pair<pair<string, int>, vector<string> >(pair<string, int>(start, 1), vector<string>(1, start)));
        
        vector<vector<string>> ans;
        int ansd = 0x7FFFFFFF;
        
        while (!q.empty())  {
            string s = q.front().first.first;
            int d = q.front().first.second;
            vector<string> v = q.front().second;
            q.pop();
            
            if (s == end)   {
                if (d < ansd)   {
                    ansd = d;
                }
                if (d <= ansd)   {
                    ans.push_back(v); 
                }
            }
            
            for (int i = 0; i < s.length(); i++)    {
                string tmp = s;
                for (char c = 'a'; c <= 'z'; c++)   {
                    if (s[i] == c)
                        continue;
                    tmp[i] = c;
                    
                    if (find(v.begin(), v.end(), tmp) == v.end() && dict.find(tmp) != dict.end())   {
                        v.push_back(tmp);
                        q.push(pair<pair<string, int>, vector<string> >(pair<string, int>(tmp, d + 1), v));
                        v.pop_back();
                    }
                }
            }
        }
        
        return ans;
    }
};