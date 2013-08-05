class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ans;
        if (L.size() == 0)
            return ans;
        
        int n = S.length();
        int wn = L.size();
        int m = L[0].length();
        
        map<string, int> hash;
        for (int i = 0; i < wn; i++)  {
            hash[L[i]] = i;
        }
        
        int *occur = new int[wn], on;
        int *occurMax = new int[wn];
        
        memset(occurMax, 0, sizeof(int) * wn);
        for (int i = 0; i < wn; i++)    {
            occurMax[hash[L[i]]]++;
        }
        
        for (int i = 0; i < m; i++) {
            memset(occur, 0, sizeof(int) * wn);
            on = 0;
            int s = i, p = -1;
            while (s + m - 1 < n)   {
                if (p >= 0 && hash.find(S.substr(p, m)) != hash.end())  {
                    int v = hash[S.substr(p, m)];
                    occur[v]--;
                    if (occur[v] < occurMax[v])
                        on--;
                }
                
                if (hash.find(S.substr(s, m)) != hash.end())  {
                    int v = hash[S.substr(s, m)];
                    occur[v]++;
                    if (occur[v] <= occurMax[v])
                        on++;
                }
                
                if (on == wn)   {
                    ans.push_back(p + m);
                }
                
                s += m;
                p = s - wn * m;
            }
        }
        
        return ans;
    }    
};