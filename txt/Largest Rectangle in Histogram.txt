class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        stack<int> si, sh;
        int ans = 0;
        if (height.size() == 0)
            return 0;
        
        for (int i = 0; i <= height.size(); i++) {
            int h = (i == height.size()) ? 0: height[i];
            
            if (sh.empty() || h > sh.top())   {
                si.push(i);
                sh.push(height[i]);
            }
            else if (h < sh.top())   {
                int mn = 0x7FFFFFFF;
                int lasti;
                while (!si.empty() && sh.top() > h)    {
                    mn = min(mn, sh.top());
                    ans = max(ans, mn * (i - si.top()));
                    
                    lasti = si.top();
                    sh.pop(); si.pop();
                }
                sh.push(h);
                si.push(lasti);
            }
        }
        
        return ans;
    }
};