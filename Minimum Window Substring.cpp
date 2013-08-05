class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (T == "")
            return "";
            
        string ans = "";
        
        int times[260], Tch[260];
        
        memset(times, 0, sizeof(times));
        memset(Tch, 0, sizeof(Tch));
        for (int i = 0; i < T.length(); i++)    {
            Tch[T[i]]++;
        }
        
        int words = 0;
        int left = 0, right = -1;
        
        while (right  < (int)S.length())  {
            if (words < T.length())   {
                right++;
                if (right >= S.length())
                    break;
                times[S[right]]++;
                if (times[S[right]] <= Tch[S[right]])
                    words++;
            }
            else    {
                times[S[left]]--;
                if (times[S[left]] < Tch[S[left]])
                    words--;
                left++;
            }
            
            if (words >= T.length() && (ans == "" || right - left + 1 < ans.length()))   {
                ans = S.substr(left, right - left + 1); 
            }
        }
        
    
        return ans;
    }
};